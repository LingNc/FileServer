#pragma once
#include <string>
#include "json.hpp"
#include "yaml.h"

namespace yamjson{

    nlohmann::json yaml_to_json(const std::string &yaml_str);
    std::string json_to_yaml(const nlohmann::json &j);

    // 模板接口：YAML 字符串转任意类型
    // T 需支持 nlohmann::json 的 from_json
    // 例：MyType t = from_yaml<MyType>(yaml_str);
    template <typename T>
    T from_yaml(const std::string &yaml_str);

    // 模板接口：任意类型转 YAML 字符串
    // T 需支持 nlohmann::json 的 to_json
    // 例：std::string yml = to_yaml(obj);
    template <typename T>
    std::string to_yaml(const T &value);

} // namespace yamjson
