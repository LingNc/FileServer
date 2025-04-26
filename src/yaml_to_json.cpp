#include "yaml_to_json.h"
#include <stdexcept>
#include <regex>
#include <sstream>
#include <fstream>

namespace yamjson {

// YAML 转 JSON 的核心递归转换函数
nlohmann::json yaml_node_to_json(const YAML::Node &node){
    using namespace nlohmann;

    switch(node.Type()){
    case YAML::NodeType::Scalar: {
        // 尝试解析标量类型
        try{
            return node.as<int>();
        }
        catch(...){
            try{
                return node.as<double>();
            }
            catch(...){
                std::string s=node.as<std::string>();

                // 处理常见布尔值表示
                if(s=="true"||s=="True"||s=="TRUE") return true;
                if(s=="false"||s=="False"||s=="FALSE") return false;

                // 处理 YAML 的 yes/no 布尔表示
                if(s=="yes"||s=="Yes"||s=="YES") return true;
                if(s=="no"||s=="No"||s=="NO") return false;

                // 处理 null
                if(s=="null"||s=="Null"||s=="NULL") return nullptr;

                return s;
            }
        }
    }
    case YAML::NodeType::Sequence: {
        json arr=json::array();
        for(const auto &child:node){
            arr.push_back(yaml_node_to_json(child));
        }
        return arr;
    }
    case YAML::NodeType::Map: {
        json obj=json::object();
        for(const auto &pair:node){
            std::string key=pair.first.as<std::string>();
            obj[key]=yaml_node_to_json(pair.second);
        }
        return obj;
    }
    case YAML::NodeType::Null:
        return nullptr;
    default:
        throw std::runtime_error("Unsupported YAML node type");
    }
}

// JSON 转 YAML 的核心递归转换函数
YAML::Node json_to_yaml_node(const nlohmann::json &j){
    using namespace nlohmann;

    if(j.is_object()){
        YAML::Node node(YAML::NodeType::Map);
        for(auto &[key,value]:j.items()){
            node[key]=json_to_yaml_node(value);
        }
        return node;
    }
    if(j.is_array()){
        YAML::Node node(YAML::NodeType::Sequence);
        for(auto &element:j){
            node.push_back(json_to_yaml_node(element));
        }
        return node;
    }
    if(j.is_null()){
        return YAML::Node(YAML::NodeType::Null);
    }
    if(j.is_boolean()){
        return YAML::Node(j.get<bool>());
    }
    if(j.is_number_integer()){
        return YAML::Node(j.get<int64_t>());
    }
    if(j.is_number_float()){
        return YAML::Node(j.get<double>());
    }
    if(j.is_string()){
        return YAML::Node(j.get<std::string>());
    }
    throw std::runtime_error("Unsupported JSON type");
}

// 公开接口：YAML 字符串 -> JSON 对象
nlohmann::json yaml_to_json(const std::string &yaml_str){
    try{
        YAML::Node root=YAML::Load(yaml_str);
        return yaml_node_to_json(root);
    }
    catch(const YAML::Exception &e){
        throw std::runtime_error(std::string("YAML parse error: ")+e.what());
    }
}

// 公开接口：JSON 对象 -> YAML 字符串
std::string json_to_yaml(const nlohmann::json &j){
    try{
        YAML::Emitter emitter;
        emitter<<json_to_yaml_node(j);
        if(!emitter.good()){
            throw std::runtime_error("YAML emit error");
        }
        return emitter.c_str();
    }
    catch(const YAML::Exception &e){
        throw std::runtime_error(std::string("YAML emit error: ")+e.what());
    }
}

// YamlDocument类实现
YamlDocument::YamlDocument(const std::string& yaml_content) : original_yaml_(yaml_content) {
    // 解析YAML为JSON
    try {
        json_data_ = yaml_to_json(yaml_content);
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("无法解析YAML文档: ") + e.what());
    }
}

std::string YamlDocument::dump() const {
    if (original_yaml_.empty()) {
        // 如果没有原始YAML，直接转换为YAML
        return json_to_yaml(json_data_);
    }

    // 解析原始YAML文档结构
    YAML::Node original_node = YAML::Load(original_yaml_);

    // 创建YAML解析器保留原始注释
    try {
        // 这里我们需要手动操作YAML内容，保留注释
        // 由于yaml-cpp库不直接支持操作注释，我们需要使用文本处理方法

        // 将JSON数据应用到YAML文档
        std::string result = original_yaml_;
        std::string temp_file = "temp_yaml_dump.yaml";

        // 将修改后的JSON转为YAML（不含注释）
        std::string modified_yaml = json_to_yaml(json_data_);

        // 逐行处理，保留注释但更新值
        std::istringstream original_stream(original_yaml_);
        std::istringstream modified_stream(modified_yaml);

        std::vector<std::string> original_lines;
        std::string line;
        while (std::getline(original_stream, line)) {
            original_lines.push_back(line);
        }

        std::map<std::string, std::string> modified_values;
        std::string key_path;
        while (std::getline(modified_stream, line)) {
            // 找出键值对
            std::regex key_value_regex(R"((\s*)([\w\-\.]+)(\s*):(\s*)(.+))");
            std::smatch matches;
            if (std::regex_match(line, matches, key_value_regex)) {
                std::string key = matches[2].str();
                std::string value = matches[5].str();
                modified_values[key] = value;
            }
        }

        // 处理原始YAML，保留注释并更新值
        std::vector<std::string> result_lines;
        for (const auto& original_line : original_lines) {
            std::string processed_line = original_line;

            // 检查是否是注释行
            if (original_line.find('#') != std::string::npos) {
                result_lines.push_back(original_line); // 保留注释行
                continue;
            }

            // 检查是否是键值对
            std::regex key_value_regex(R"((\s*)([\w\-\.]+)(\s*):(\s*)(.+))");
            std::smatch matches;
            if (std::regex_match(original_line, matches, key_value_regex)) {
                std::string indent = matches[1].str();
                std::string key = matches[2].str();
                std::string mid_space1 = matches[3].str();
                std::string mid_space2 = matches[4].str();

                // 检查这个键是否有更新值
                auto it = modified_values.find(key);
                if (it != modified_values.end()) {
                    processed_line = indent + key + mid_space1 + ":" + mid_space2 + it->second;
                }
            }

            result_lines.push_back(processed_line);
        }

        // 将处理后的行组合回字符串
        std::string final_result;
        for (const auto& line : result_lines) {
            final_result += line + "\n";
        }

        return final_result;
    } catch (const std::exception& e) {
        // 如果出错，回退到不保留注释的方法
        return json_to_yaml(json_data_);
    }
}

bool YamlDocument::update_value(const std::vector<std::string>& path, const nlohmann::json& value) {
    try {
        // 创建指向json_data_的指针
        nlohmann::json* current = &json_data_;

        // 遍历路径
        for (size_t i = 0; i < path.size(); ++i) {
            const std::string& key = path[i];

            // 最后一个路径节点
            if (i == path.size() - 1) {
                (*current)[key] = value;
                return true;
            }

            // 检查中间节点是否存在
            if (!current->contains(key) || !(*current)[key].is_object()) {
                (*current)[key] = nlohmann::json::object();
            }

            // 移动到下一级
            current = &(*current)[key];
        }

        return false; // 空路径
    } catch (const std::exception& e) {
        return false;
    }
}

} // namespace yamjson