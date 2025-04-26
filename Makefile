# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g  # 开发环境编译选项
Cpp_flags_release = -std=c++17 -Wall -Wextra -O3 -DNDEBUG  # 生产环境编译选项

# 源文件和目标文件
Src = src/main.cpp src/yaml_to_json.cpp
Obj = $(patsubst src/%.cpp,build/%.o,$(Src))
Obj_release = $(patsubst src/%.cpp,build/%_release.o,$(Src))

# 目录配置
Include = include
Ext = ext
Lib_dir = lib
Module_dir = module
Yaml_builder_dir = $(Module_dir)/yaml-cpp-builder

# 如果没有创建就创建build和example目录
$(shell mkdir -p build)
$(shell mkdir -p $(Include))
$(shell mkdir -p $(Ext))
$(shell mkdir -p $(Lib_dir))
$(shell mkdir -p example)

# ====== main 主程序构建 ======

# 构建 main（开发版本，带调试功能）
main : $(Obj) | link check-yaml
	@echo "正在链接开发版本（带调试功能）..."
	$(Cpp) $(Cpp_flags) -o $@ $^
	@echo "开发版本构建完成！"

# 构建 main-release（生产版本，优化性能）
main-release : $(Obj_release) | link check-yaml
	@echo "正在链接生产版本（优化性能）..."
	$(Cpp) $(Cpp_flags_release) -o $@ $^
	@echo "生产版本构建完成！"

# 通用规则：编译所有源文件（开发版本）
build/%.o : src/%.cpp
	@echo "正在编译 $< (开发版本)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 通用规则：编译所有源文件（生产版本）
build/%_release.o : src/%.cpp
	@echo "正在编译 $< (生产版本)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags_release) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 特殊规则：编译yaml_to_json.cpp时不使用_GLIBCXX_DEBUG标志
# build/yaml_to_json.o : src/yaml_to_json.cpp
# 	@echo "正在编译 $< (开发版本，无调试标志)..."
# 	@mkdir -p $(dir $@)
# 	$(Cpp) -std=c++17 -Wall -Wextra -g -c $< -o $@ -I$(Include) -I$(Ext)
# 	@echo "编译完成 $@ ！"

# 特殊规则：编译yaml_to_json.cpp（生产版本）
# build/yaml_to_json_release.o : src/yaml_to_json.cpp
# 	@echo "正在编译 $< (生产版本)..."
# 	@mkdir -p $(dir $@)
# 	$(Cpp) $(Cpp_flags_release) -c $< -o $@ -I$(Include) -I$(Ext)
# 	@echo "编译完成 $@ ！"

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

# ====== yaml 库检查和构建 ======

# 检查 yaml-cpp.hpp 是否存在（合并单头文件版）
.PHONY : check-yaml
check-yaml :
	@echo "检查YAML合并单头文件是否存在..."
	@if [ ! -f "$(Ext)/yaml-cpp.hpp" ]; then \
		echo "YAML合并单头文件不存在，需要生成"; \
		$(MAKE) yaml_all; \
	else \
		echo "YAML合并单头文件已存在，跳过生成"; \
	fi

# 使用子模块构建yaml（合并单头文件版）
.PHONY : yaml_all
yaml_all :
	@echo "使用yaml-cpp-builder子模块生成合并单头文件..."
	@$(MAKE) -C $(Yaml_builder_dir) merged-header
	@mkdir -p $(Include)
	@ln -sf ../$(Yaml_builder_dir)/include/yaml-cpp.hpp $(Ext)/yaml-cpp.hpp
	@echo "yaml-cpp.hpp 链接创建完成！"

# 清理 yaml 构建文件（调用子模块的清理目标）
.PHONY : clean-yaml
clean-yaml :
	@echo "正在清理 YAML 构建文件..."
	@$(MAKE) -C $(Yaml_builder_dir) clean
	@if [ -L "$(Include)/yaml-cpp.hpp" ]; then \
		rm -f $(Include)/yaml-cpp.hpp; \
		echo "已删除 $(Include)/yaml-cpp.hpp 链接"; \
	fi
	@echo "YAML 构建文件清理完成！"

# ====== 示例程序目标 ======

# yaml_to_json 目标文件（供示例程序使用）
.PHONY : yaml_to_json_obj
yaml_to_json_obj : build/yaml_to_json.o
	@echo "确保 yaml_to_json.o 已构建完成"

# 调用example目录中的Makefile
.PHONY : example
example : yaml_to_json_obj check-yaml
	@echo "正在调用example目录的Makefile构建示例程序..."
	$(MAKE) -C example example

# 运行示例程序
.PHONY : run-example
run-example : example
	@echo "正在调用example目录的Makefile运行示例程序..."
	$(MAKE) -C example run-example

# 直接测试程序目标
.PHONY : direct-test run-direct-test
direct-test run-direct-test:
	@echo "正在调用example目录的Makefile运行 $@..."
	$(MAKE) -C example $@

# ====== 其他内容 ======

# make help
# 显示帮助信息
.PHONY : help
help :
	@echo "FileServer Makefile 帮助"
	@echo "------------------------"
	@echo "make             - 构建主程序（开发版本，带调试功能）"
	@echo "make main        - 构建主程序（开发版本，带调试功能）"
	@echo "make main-release- 构建主程序（生产版本，优化性能）"
	@echo "【示例程序】"
	@echo "make example     - 构建YAML-JSON示例程序"
	@echo "make run-example - 运行YAML-JSON示例程序"
	@echo "make direct-test - 构建直接使用YAML-CPP的测试程序"
	@echo "make run-direct-test - 运行直接使用YAML-CPP的测试程序"
	@echo "【清理】"
	@echo "make clean       - 清理构建文件"
	@echo "make clean-all   - 清理所有文件，包括YAML库"
	@echo "【YAML库】"
	@echo "make yaml_all    - 生成yaml-cpp.hpp全合并版单头文件"
	@echo "make clean-yaml  - 清理YAML构建文件"
	@echo "make help        - 显示此帮助信息"

# 清理
.PHONY : clean
clean :
	@echo "正在清理..."
	rm -f build/*.o build/*_release.o main main-release
	$(MAKE) -C example clean
	@echo "清理完成！"

# 全部清理（包括 YAML）
.PHONY : clean-all
clean-all : clean clean-yaml
	@echo "全部清理完成！"