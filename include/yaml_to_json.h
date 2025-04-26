#pragma once
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "json.hpp"

// 根据编译标志选择不同的YAML头文件
#if defined(USE_YAML_MERGED_HEADER)
    // 使用合并单头文件版本
    #include "yaml-cpp.hpp"
#else
    // 默认使用静态库版本
    #include "yaml.hpp"
#endif

namespace yamjson {
    // YAML -> JSON 核心转换函数
    nlohmann::json yaml_to_json(const std::string &yaml_str);
    nlohmann::json yaml_node_to_json(const YAML::Node &node);

    // JSON -> YAML 核心转换函数
    std::string json_to_yaml(const nlohmann::json &j);
    YAML::Node json_to_yaml_node(const nlohmann::json &j);

    // 保留注释的YAML转换
    class YamlDocument {
    private:
        std::string original_yaml_;  // 保存原始YAML文本，包含注释
        nlohmann::json json_data_;   // 保存转换后的JSON数据

    public:
        // 构造函数
        explicit YamlDocument(const std::string& yaml_content);
        YamlDocument() = default;

        // 获取JSON数据
        const nlohmann::json& json() const { return json_data_; }
        nlohmann::json& json() { return json_data_; }

        // 获取原始YAML，包含注释
        const std::string& original_yaml() const { return original_yaml_; }

        // 应用JSON修改并生成新的YAML（保留注释）
        std::string dump() const;

        // 修改特定路径的值，返回是否成功修改
        bool update_value(const std::vector<std::string>& path, const nlohmann::json& value);
    };
}

// 以下是与 nlohmann::json 集成的函数，基于 ADL 机制
namespace nlohmann {
    // 从 YAML 字符串解析
    inline void from_yaml(const std::string& yaml_str, json& j) {
        j = yamjson::yaml_to_json(yaml_str);
    }

    // YAML 字符串 -> 任意类型 (遵循 from_json 的模式)
    template<typename ValueType>
    inline void from_yaml(const std::string& yaml_str, ValueType& val) {
        json j = yamjson::yaml_to_json(yaml_str);
        j.get_to(val);  // 使用 json 的 get_to 方法
    }

    // 将 JSON 转换为 YAML 字符串
    inline std::string to_yaml(const json& j) {
        return yamjson::json_to_yaml(j);
    }
}

// 为与 YAML 相关的类型提供 ADL 序列化器
namespace nlohmann {
    // 单独的命名空间，存放 YAML 相关的类型
    namespace yaml {
        // 包装类，表示一个 YAML 文档（保留注释版本）
        class document {
        private:
            std::shared_ptr<yamjson::YamlDocument> doc_;

        public:
            // 从 YAML 字符串构造
            explicit document(const std::string& yaml_content)
                : doc_(std::make_shared<yamjson::YamlDocument>(yaml_content)) {}

            // 默认构造函数
            document() : doc_(std::make_shared<yamjson::YamlDocument>()) {}

            // 获取JSON数据
            nlohmann::json& get_json() { return doc_->json(); }
            const nlohmann::json& get_json() const { return doc_->json(); }

            // 生成YAML（保留注释）
            std::string dump() const { return doc_->dump(); }

            // 修改特定路径的值
            bool update(const std::vector<std::string>& path, const nlohmann::json& value) {
                return doc_->update_value(path, value);
            }

            // 快捷访问接口，保持与原始接口兼容
            std::string content() const { return dump(); }
        };
    }

    // 为 YAML 文档类型特化 ADL 序列化器
    template<>
    struct adl_serializer<yaml::document> {
        // YAML 文档 -> JSON
        static void from_json(const json& j, yaml::document& doc) {
            // 注意：这里会丢失原始的注释信息
            // 但由于必须支持这种转换方式，我们只能输出不含注释的YAML
            std::string yaml_str = to_yaml(j);
            doc = yaml::document(yaml_str);
        }

        // JSON -> YAML 文档
        static void to_json(json& j, const yaml::document& doc) {
            j = doc.get_json();
        }
    };
}
