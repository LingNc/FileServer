# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG

# 源文件和目标文件
Src = src/main.cpp src/yaml_to_json.cpp
Obj = $(patsubst src/%.cpp,build/%.o,$(Src))

# YAML 相关配置
YAML_REPO = yaml-cpp
YAML_GIT = https://github.com/jbeder/yaml-cpp.git
YAML_BUILD_DIR = build_yaml
YAML_HEADER_SCRIPT = $(YAML_BUILD_DIR)/make_yaml_header.sh
YAML_ALL_SCRIPT = $(YAML_BUILD_DIR)/make_yaml_all.sh

# 链接静态库
Lib = lib/libyaml.a

# 头文件
Include = include
Ext = ext
Lib_dir = lib

# 如果没有创建就创建build和example目录
$(shell mkdir -p build)
$(shell mkdir -p $(Ext))
$(shell mkdir -p $(Lib_dir))
$(shell mkdir -p example)

# ====== main 主程序构建 ======

# 构建 main
main : $(Obj) | link check-yaml
	@echo "正在链接..."
	$(Cpp) $(Cpp_flags) -o $@ $^ $(Lib)
	@echo "构建完成！"

# 通用规则：编译所有源文件
build/%.o : src/%.cpp
	@echo "正在编译 $< ..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 复制子模块的头文件到include位置
.PHONY : link
link :
	@echo "检查模块loglib库是否链接..."
	@if [ ! -e ./$(Ext)/loglib.hpp ]; then \
		ln -s ../module/loglib/loglib.hpp ./$(Ext)/loglib.hpp; \
		echo "链接创建完成！"; \
	else \
		echo "链接已存在，跳过创建"; \
	fi

# ====== yaml 库构建 ======

# 检查 yaml.hpp 或者 yaml-cpp.hpp 是否存在
.PHONY : check-yaml
check-yaml :
	@echo "检查YAML库文件是否存在..."
	@if [ ! -f "$(Ext)/yaml.hpp" ] && [ ! -f "$(Ext)/yaml-cpp.hpp" ]; then \
		echo "YAML头文件不存在，需要生成"; \
		$(MAKE) yaml_header; \
	else \
		echo "YAML头文件已存在，跳过生成"; \
	fi

# 检查 yaml-cpp 仓库是否存在，不存在则下载
.PHONY : check-yaml-repo
check-yaml-repo :
	@if [ ! -d "$(YAML_REPO)" ]; then \
		echo "YAML-CPP 仓库不存在，正在下载..."; \
		git clone $(YAML_GIT) $(YAML_REPO); \
		echo "YAML-CPP 仓库下载完成！"; \
	else \
		echo "YAML-CPP 仓库已存在，跳过下载"; \
	fi

# 生成单一头文件版 yaml.hpp
.PHONY : yaml_header
yaml_header : check-yaml-repo
	@echo "正在生成 yaml.hpp 单头文件..."
	@chmod +x $(YAML_HEADER_SCRIPT)
	@./$(YAML_HEADER_SCRIPT)
	@echo "yaml.hpp 生成完成！"

# 生成全部合并版 yaml-cpp.hpp
.PHONY : yaml_all
yaml_all : check-yaml-repo
	@echo "正在生成 yaml-cpp.hpp 全合并版..."
	@chmod +x $(YAML_ALL_SCRIPT)
	@./$(YAML_ALL_SCRIPT)
	@echo "yaml-cpp.hpp 生成完成！"

# 清理 yaml 构建文件（保留仓库）
.PHONY : clean-yaml
clean-yaml :
	@echo "正在清理 YAML 构建文件..."
	@if [ -d "$(YAML_REPO)/build" ]; then \
		rm -rf $(YAML_REPO)/build; \
		echo "已删除 $(YAML_REPO)/build 目录"; \
	fi
	@if [ -f "$(Ext)/yaml.hpp" ]; then \
		rm -f $(Ext)/yaml.hpp; \
		echo "已删除 $(Ext)/yaml.hpp 文件"; \
	fi
	@if [ -f "$(Ext)/yaml-cpp.hpp" ]; then \
		rm -f $(Ext)/yaml-cpp.hpp; \
		echo "已删除 $(Ext)/yaml-cpp.hpp 文件"; \
	fi
	@if [ -f "$(Lib_dir)/libyaml.a" ]; then \
		rm -f $(Lib_dir)/libyaml.a; \
		echo "已删除 $(Lib_dir)/libyaml.a 文件"; \
	fi
	@if [ -d "temp" ]; then \
		rm -rf temp; \
		echo "已删除临时目录"; \
	fi
	@echo "YAML 构建文件清理完成！"

# 清理yaml构建缓存
.PHONY : clean-yaml-temp
clean-yaml-temp :
	@echo "正在清理 YAML 临时构建文件..."
	@if [ -d "temp" ]; then \
		rm -rf temp; \
		echo "已删除临时构建目录"; \
	fi
	@echo "YAML 临时构建文件清理完成！"

# 清理 yaml 仓库
.PHONY : clean-yaml-git
clean-yaml-git :
	@echo "正在清理 YAML 仓库..."
	@if [ -d "$(YAML_REPO)" ]; then \
		rm -rf $(YAML_REPO); \
		echo "已删除 $(YAML_REPO) 仓库"; \
		@echo "YAML 仓库清理完成！"
	fi

# ======示例程序======

# yaml_to_json 目标文件（单独定义，用于示例程序）
Yaml_to_json_obj = build/yaml_to_json.o

# 示例程序
Example_src = example/yaml_json_example.cpp
Example_target = example/yaml_json_example

# 编译示例程序（依赖yaml_to_json的目标文件）
.PHONY : example
example : $(Yaml_to_json_obj) check-yaml
	@echo "正在编译YAML-JSON示例程序..."
	$(Cpp) $(Cpp_flags) -o $(Example_target) $(Example_src) $(Yaml_to_json_obj) $(Lib) -I$(Include) -I$(Ext)
	@echo "示例程序编译完成！可以通过 ./$(Example_target) 运行"

# 运行示例程序
.PHONY : run-example
run-example : example
	@echo "正在运行YAML-JSON示例程序..."
	./$(Example_target)

# ====== 其他内容 ======

# make help
# 显示帮助信息
.PHONY : help
help :
	@echo "FileServer Makefile 帮助"
	@echo "------------------------"
	@echo "make          - 构建主程序"
	@echo "make example  - 构建YAML-JSON示例程序"
	@echo "make run-example - 运行YAML-JSON示例程序"
	@echo "make clean    - 清理构建文件"
	@echo "make clean-all- 清理所有文件，包括YAML库"
	@echo "make yaml_header - 仅生成yaml.hpp单头文件"
	@echo "make yaml_all    - 生成yaml-cpp.hpp全合并版"
	@echo "make clean-yaml  - 清理YAML构建文件"
	@echo "make clean-yaml-git - 清理YAML仓库"
	@echo "make help     - 显示此帮助信息"

# 清理
.PHONY : clean
clean :
	@echo "正在清理..."
	rm -f build/*.o main $(Example_target) example/*.yaml
	clean-yaml-git
	@echo "清理完成！"

# 全部清理（包括 YAML）
.PHONY : clean-all
clean-all : clean clean-yaml
	@echo "全部清理完成！"