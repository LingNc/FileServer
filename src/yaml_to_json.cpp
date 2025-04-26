#include "yaml_to_json.h"
#include <stdexcept>

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

} // namespace yamjson