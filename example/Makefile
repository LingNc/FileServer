# ===== 示例程序的Makefile =====
# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g

# 定义相对路径
Root_dir = ..
Include_dir = $(Root_dir)/include
Ext_dir = $(Root_dir)/ext
Lib_dir = $(Root_dir)/lib
Build_dir = $(Root_dir)/build
Yaml_repo = $(Root_dir)/yaml-cpp

# 设置YAML库类型（支持static和merged两种）
# 可以通过 make YAML_TYPE=merged 命令指定使用合并单头文件版
YAML_TYPE ?= static

# YAML库类型标志
YAML_FLAGS_STATIC = -DUSE_YAML_STATIC_LIB
YAML_FLAGS_MERGED = -DUSE_YAML_MERGED_HEADER

# 根据YAML库类型设置相应的编译标志和对象文件
ifeq ($(YAML_TYPE),static)
    YAML_FLAGS = $(YAML_FLAGS_STATIC)
    Yaml_to_json_obj = $(Build_dir)/yaml_to_json.o
    Yaml_lib = $(Lib_dir)/libyaml.a
    Example_postfix =
else ifeq ($(YAML_TYPE),merged)
    YAML_FLAGS = $(YAML_FLAGS_MERGED)
    Yaml_to_json_obj = $(Build_dir)/yaml_to_json_merged.o
    Yaml_lib =
    Example_postfix = _merged
else
    $(error "不支持的YAML库类型 '$(YAML_TYPE)'，支持的类型有: static, merged")
endif

# 示例程序定义
Example_src = yaml_json_example.cpp
Example_target = yaml_json_example$(Example_postfix)

# 直接使用原始YAML-CPP库的测试程序
Direct_test_src = yaml_direct_test.cpp
Direct_test_target = yaml_direct_test

# 默认目标：编译所有示例
.PHONY : all
all : example direct-test

# 编译主要示例程序（依赖yaml_to_json的目标文件）
.PHONY : example
example :
	@echo "正在编译YAML-JSON示例程序($(YAML_TYPE)版)..."
ifeq ($(YAML_TYPE),static)
	$(Cpp) $(Cpp_flags) $(YAML_FLAGS) -o $(Example_target) $(Example_src) $(Yaml_to_json_obj) $(Yaml_lib) -I$(Include_dir) -I$(Ext_dir)
else
	$(Cpp) $(Cpp_flags) $(YAML_FLAGS) -o $(Example_target) $(Example_src) $(Yaml_to_json_obj) -I$(Include_dir) -I$(Ext_dir)
endif
	@echo "示例程序编译完成！可以通过 ./$(Example_target) 运行"

# 运行示例程序
.PHONY : run-example
run-example : example
	@echo "正在运行YAML-JSON示例程序($(YAML_TYPE)版)..."
	./$(Example_target)

# 编译直接使用原始YAML-CPP库的测试程序
.PHONY : direct-test
direct-test :
	@echo "正在编译直接使用YAML-CPP原始库的测试程序..."
	$(Cpp) -std=c++17 -Wall -g -o $(Direct_test_target) $(Direct_test_src) $(Yaml_repo)/build/libyaml-cpp.a -I$(Yaml_repo)/include
	@echo "直接测试程序编译完成！可以通过 ./$(Direct_test_target) 运行"

# 运行直接使用原始YAML-CPP库的测试程序
.PHONY : run-direct-test
run-direct-test : direct-test
	@echo "正在运行直接使用原始YAML-CPP库的测试程序..."
	./$(Direct_test_target)

# 清理
.PHONY : clean
clean :
	@echo "正在清理示例程序..."
	rm -f $(Example_target) yaml_json_example_merged $(Direct_test_target) *.yaml
	@echo "清理完成！"

# 帮助信息
.PHONY : help
help :
	@echo "示例程序 Makefile 帮助"
	@echo "----------------------"
	@echo "make            - 构建所有示例程序(默认使用静态库版YAML)"
	@echo "make YAML_TYPE=static example   - 构建使用静态库版的YAML-JSON示例程序"
	@echo "make YAML_TYPE=merged example   - 构建使用合并头文件版的YAML-JSON示例程序"
	@echo "make YAML_TYPE=static run-example - 运行使用静态库版的YAML-JSON示例程序"
	@echo "make YAML_TYPE=merged run-example - 运行使用合并头文件版的YAML-JSON示例程序"
	@echo "make direct-test   - 构建直接使用YAML-CPP的测试程序"
	@echo "make run-direct-test - 运行直接使用YAML-CPP的测试程序"
	@echo "make clean     - 清理示例程序"
	@echo "make help      - 显示此帮助信息"