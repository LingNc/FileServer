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

# 库文件
Yaml_lib = $(Lib_dir)/libyaml.a
Yaml_debug_lib = $(Lib_dir)/libyaml-debug.a
Yaml_to_json_obj = $(Build_dir)/yaml_to_json.o

# 示例程序定义
Example_src = yaml_json_example.cpp
Example_target = yaml_json_example

# 简化测试程序
Simple_test_src = yaml_simple_test.cpp
Simple_test_target = yaml_simple_test

# 最小YAML测试程序
Minimal_test_src = yaml_minimal_test.cpp
Minimal_test_target = yaml_minimal_test

# 直接使用原始YAML-CPP库的测试程序
Direct_test_src = yaml_direct_test.cpp
Direct_test_target = yaml_direct_test

# 默认目标：编译所有示例
.PHONY : all
all : example simple-test minimal-test

# 编译主要示例程序（依赖yaml_to_json的目标文件）
.PHONY : example
example :
	@echo "正在编译YAML-JSON示例程序..."
	$(Cpp) $(Cpp_flags) -o $(Example_target) $(Example_src) $(Yaml_to_json_obj) $(Yaml_lib) -I$(Include_dir) -I$(Ext_dir)
	@echo "示例程序编译完成！可以通过 ./$(Example_target) 运行"

# 运行示例程序
.PHONY : run-example
run-example : example
	@echo "正在运行YAML-JSON示例程序..."
	./$(Example_target)

# 编译简化测试程序
.PHONY : simple-test
simple-test :
	@echo "正在编译简化YAML测试程序..."
	$(Cpp) $(Cpp_flags) -o $(Simple_test_target) $(Simple_test_src) $(Yaml_debug_lib) -I$(Include_dir) -I$(Ext_dir)
	@echo "简化测试程序编译完成！可以通过 ./$(Simple_test_target) 运行"

# 运行简化测试程序
.PHONY : run-simple-test
run-simple-test : simple-test
	@echo "正在运行简化YAML测试程序..."
	./$(Simple_test_target)

# 编译最小YAML测试程序
.PHONY : minimal-test
minimal-test :
	@echo "正在编译最小YAML测试程序..."
	$(Cpp) $(Cpp_flags) -o $(Minimal_test_target) $(Minimal_test_src) $(Yaml_debug_lib) -I$(Include_dir) -I$(Ext_dir)
	@echo "最小YAML测试程序编译完成！可以通过 ./$(Minimal_test_target) 运行"

# 运行最小YAML测试程序
.PHONY : run-minimal-test
run-minimal-test : minimal-test
	@echo "正在运行最小YAML测试程序..."
	./$(Minimal_test_target)

# 最小YAML测试程序 (无调试标志)
.PHONY : minimal-test-nodebug
minimal-test-nodebug :
	@echo "正在编译最小YAML测试程序 (无调试标志)..."
	g++ -std=c++17 -Wall -g -o $(Minimal_test_target)_nodebug $(Minimal_test_src) $(Yaml_lib) -I$(Include_dir) -I$(Ext_dir)
	@echo "最小测试程序编译完成！可以通过 ./$(Minimal_test_target)_nodebug 运行"

# 运行最小YAML测试程序 (无调试标志)
.PHONY : run-minimal-test-nodebug
run-minimal-test-nodebug : minimal-test-nodebug
	@echo "正在运行最小YAML测试程序 (无调试标志)..."
	./$(Minimal_test_target)_nodebug

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
	rm -f $(Example_target) $(Simple_test_target) $(Minimal_test_target) $(Direct_test_target) *.yaml
	@echo "清理完成！"

# 帮助信息
.PHONY : help
help :
	@echo "示例程序 Makefile 帮助"
	@echo "----------------------"
	@echo "make            - 构建所有示例程序"
	@echo "make example    - 构建YAML-JSON示例程序"
	@echo "make run-example- 运行YAML-JSON示例程序"
	@echo "make simple-test- 构建简化测试程序"
	@echo "make minimal-test- 构建最小测试程序（调试版）"
	@echo "make minimal-test-nodebug - 构建最小测试程序（非调试版）"
	@echo "make direct-test- 构建直接使用YAML-CPP的测试程序"
	@echo "make clean     - 清理示例程序"
	@echo "make help      - 显示此帮助信息"