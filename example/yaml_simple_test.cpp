#include <iostream>
#include <string>
#include "json.hpp"
#include "yaml.hpp"  // 直接包含YAML库

/**
 * 简化版的YAML-JSON转换示例
 * 这个版本减少了功能，只测试基本的YAML解析
 */
int main() {
    try {
        std::cout << "=== 简化版的YAML-JSON转换测试 ===" << std::endl;

        // 简单的YAML字符串
        std::string yaml_str = "key: value\nnum: 123\nbool: true";

        std::cout << "原始YAML:\n" << yaml_str << std::endl;

        // 直接使用YAML-CPP解析
        std::cout << "\n尝试直接用YAML-CPP解析..." << std::endl;
        try {
            YAML::Node node = YAML::Load(yaml_str);
            std::cout << "YAML-CPP解析成功！" << std::endl;
            std::cout << "key: " << node["key"].as<std::string>() << std::endl;
            std::cout << "num: " << node["num"].as<int>() << std::endl;
            std::cout << "bool: " << (node["bool"].as<bool>() ? "true" : "false") << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "YAML-CPP解析错误: " << e.what() << std::endl;
        }

        // 使用自定义的yaml_to_json函数
        std::cout << "\n不尝试使用自定义yaml_to_json函数" << std::endl;

        std::cout << "\n=== 简化测试结束 ===" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "程序错误: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "未知错误" << std::endl;
        return 1;
    }
}