# ===== 示例程序的Makefile =====
# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g

# 定义相对路径
Root_dir = ..
Include_dir = $(Root_dir)/include
Ext_dir = $(Root_dir)/ext
Build_dir = $(Root_dir)/build
Yaml_repo = $(Root_dir)/yaml-cpp

# 使用合并单头文件版作为默认版本
# 添加YAML头文件的预处理器定义
YAML_FLAGS = -DUSE_YAML_MERGED_HEADER
Yaml_to_json_obj = $(Build_dir)/yaml_to_json.o

# 示例程序定义
Example_src = yaml_json_example.cpp
Example_target = yaml_json_example

# 默认目标：编译所有示例
.PHONY : all
all : example

# 编译主要示例程序（依赖yaml_to_json的目标文件）
.PHONY : example
example :
	@echo "正在编译YAML-JSON示例程序(合并单头文件版)..."
	$(Cpp) $(Cpp_flags) $(YAML_FLAGS) -o $(Example_target) $(Example_src) $(Yaml_to_json_obj) -I$(Include_dir) -I$(Ext_dir)
	@echo "示例程序编译完成！可以通过 ./$(Example_target) 运行"

# 运行示例程序
.PHONY : run-example
run-example : example
	@echo "正在运行YAML-JSON示例程序..."
	./$(Example_target)

# 清理
.PHONY : clean
clean :
	@echo "正在清理示例程序..."
	rm -f $(Example_target) *.yaml
	@echo "清理完成！"

# 帮助信息
.PHONY : help
help :
	@echo "示例程序 Makefile 帮助"
	@echo "----------------------"
	@echo "make            - 构建所有示例程序(使用合并单头文件版YAML)"
	@echo "make example    - 构建YAML-JSON示例程序"
	@echo "make run-example - 运行YAML-JSON示例程序"
	@echo "make clean     - 清理示例程序"
	@echo "make help      - 显示此帮助信息"