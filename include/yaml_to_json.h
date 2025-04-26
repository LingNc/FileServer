#pragma once
#include <string>
#include "json.hpp"
#include "yaml.hpp"

namespace yamjson {
    // YAML -> JSON 核心转换函数
    nlohmann::json yaml_to_json(const std::string &yaml_str);
    nlohmann::json yaml_node_to_json(const YAML::Node &node);

    // JSON -> YAML 核心转换函数
    std::string json_to_yaml(const nlohmann::json &j);
    YAML::Node json_to_yaml_node(const nlohmann::json &j);
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
        // 包装类，表示一个 YAML 文档
        struct document {
            std::string content;  // YAML 内容

            // 从 YAML 字符串构造
            explicit document(const std::string& yaml_content) : content(yaml_content) {}

            // 默认构造函数
            document() = default;
        };
    }

    // 为 YAML 文档类型特化 ADL 序列化器
    template<>
    struct adl_serializer<yaml::document> {
        // YAML 文档 -> JSON
        static void from_json(const json& j, yaml::document& doc) {
            doc.content = to_yaml(j);
        }

        // JSON -> YAML 文档
        static void to_json(json& j, const yaml::document& doc) {
            j = yamjson::yaml_to_json(doc.content);
        }
    };
}
