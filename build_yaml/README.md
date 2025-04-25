# YAML-CPP 库构建工具

本目录包含两个脚本，用于方便的从 yaml-cpp 源码生成不同形式的单文件版 YAML 库。
由于 yaml-cpp 的仓库配置说明不清楚，而且不方便使用和安装，故诞生此目录。

## 前置条件

1. 克隆 yaml-cpp 仓库到项目根目录：
   ```bash
   git clone https://github.com/jbeder/yaml-cpp.git
   ```

2. 确保已安装 CMake 和 C++ 编译器：
   ```bash
   sudo apt install cmake build-essential  # Ubuntu/Debian
   ```

## 脚本说明

### 1. make_yaml_header.sh

**功能：** 生成纯头文件版 yaml-cpp 及其静态库

**生成文件：**
- `ext/yaml.hpp` - 合并后的单头文件（只包含声明）
- `lib/libyaml.a` - 编译好的静态库

**使用方法：**
```bash
chmod +x build_yaml/make_yaml_header.sh
./build_yaml/make_yaml_header.sh
```

**在项目中使用：**
```cpp
#include "yaml.hpp"  // 在 ext 目录中

// 编译时需链接静态库
// g++ your_file.cpp -o your_program -Iext -Llib -lyaml
```

**适用场景：**
- 希望保持库与代码分离
- 需要使用完整的 yaml-cpp 功能
- 代码体积和编译速度敏感

### 2. make_yaml_all.sh

**功能：** 生成全合并版 yaml-cpp 单头文件（包含所有实现，无需链接库）

**生成文件：**
- `temp/yaml-cpp.hpp` - 临时合并文件
- `ext/yaml-cpp.hpp` - 最终合并文件（包含所有声明和实现）

**使用方法：**
```bash
chmod +x build_yaml/make_yaml_all.sh
./build_yaml/make_yaml_all.sh
```

**在项目中使用：**
```cpp
#include "yaml-cpp.hpp"  // 在 ext 目录中

// 无需链接额外的库
// g++ your_file.cpp -o your_program -Iext
```

**适用场景：**
- 希望简化依赖，只需一个文件
- 项目移植、分发方便
- 不关心编译速度

## 自定义配置

两个脚本开头都有配置部分，可根据需要修改：
- 源码目录、输出目录和文件名
- 搜索路径和其他编译选项

## 注意事项

1. 脚本执行时会自动创建所需目录
2. 对于 `make_yaml_header.sh`：
   - 头文件 `yaml.hpp` 存放在 `ext` 目录
   - 静态库 `libyaml.a` 存放在 `lib` 目录
   - 使用时需要同时包含头文件并链接静态库
3. 对于 `make_yaml_all.sh`：
   - 合并后的头文件 `yaml-cpp.hpp` 仅存放在 `ext` 目录
   - 使用时只需包含该头文件，无需链接任何库
4. 如果使用 CMake，可以在 CMakeLists.txt 中配置：
   ```cmake
   # 使用 yaml.hpp + 静态库
   include_directories(ext)
   link_directories(lib)
   target_link_libraries(your_target yaml)

   # 或使用全合并版
   include_directories(ext)
   # 无需链接库
   ```