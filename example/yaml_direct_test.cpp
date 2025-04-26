#include <iostream>
#include <string>

// 直接包含原始的yaml-cpp头文件
#include "../yaml-cpp/include/yaml-cpp/yaml.h"

int main() {
    try {
        std::cout << "=== 直接使用完整YAML-CPP库测试 ===" << std::endl;

        // 非常简单的YAML字符串
        std::string yaml_str = "test: 123";

        std::cout << "测试YAML字符串: " << yaml_str << std::endl;

        // 直接使用YAML-CPP解析
        std::cout << "尝试解析..." << std::endl;

        YAML::Node node = YAML::Load(yaml_str);
        std::cout << "解析成功!" << std::endl;

        // 访问节点
        if (node["test"]) {
            std::cout << "成功读取'test'键: " << node["test"].as<int>() << std::endl;
        } else {
            std::cout << "找不到'test'键" << std::endl;
        }

        return 0;
    } catch (const YAML::Exception& e) {
        std::cerr << "YAML错误: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "标准错误: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "未知错误" << std::endl;
        return 1;
    }
}