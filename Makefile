# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG # 开发环境编译选项
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
main : $(Obj) | linklog check-yaml-debug
	@echo "正在链接开发版本（带调试功能）..."
	$(Cpp) $(Cpp_flags) -o $@ $^ -L$(Lib_dir) -lyaml-debug
	@echo "开发版本构建完成！"

# 构建 main-release（生产版本，优化性能）
main-release : $(Obj_release) | linklog check-yaml-release
	@echo "正在链接生产版本（优化性能）..."
	$(Cpp) $(Cpp_flags_release) -o $@ $^ -L$(Lib_dir) -lyaml
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

# ====== loglib 库链接 ======

# 复制子模块的头文件到include位置
.PHONY : linklog
linklog :
	@echo "检查模块loglib库是否链接..."
	@if [ ! -e ./$(Ext)/loglib.hpp ]; then \
		ln -s ../module/loglib/loglib.hpp ./$(Ext)/loglib.hpp; \
		echo "链接创建完成！"; \
	else \
		echo "链接已存在，跳过创建"; \
	fi

# ====== yaml 库检查和构建 ======

# YAML库文件路径
Yaml_include_src = $(Yaml_builder_dir)/include/yaml.hpp
Yaml_include_dest = $(Ext)/yaml.hpp
Yaml_lib_debug_src = $(Yaml_builder_dir)/lib/libyaml-debug.a
Yaml_lib_debug_dest = $(Lib_dir)/libyaml-debug.a
Yaml_lib_release_src = $(Yaml_builder_dir)/lib/libyaml.a
Yaml_lib_release_dest = $(Lib_dir)/libyaml.a

# 检查 yaml 调试版静态库和头文件是否链接
.PHONY : check-yaml-debug
check-yaml-debug :
	@echo "构建YAML调试模块"
	@$(MAKE) -C $(Yaml_builder_dir) static-lib-debug

	@echo "检查YAML调试版静态库及头文件链接..."
	@# 检查头文件目录链接是否存在
	@if [ ! -e "$(Yaml_include_dest)" ]; then \
		mkdir -p $(Include); \
		ln -s ../$(Yaml_include_src) $(Yaml_include_dest); \
		echo "YAML头文件链接创建完成"; \
	else \
		echo "YAML头文件目录链接已存在"; \
	fi
	@# 检查调试版静态库链接是否存在
	@if [ ! -e "$(Yaml_lib_debug_dest)" ]; then \
		mkdir -p $(Lib_dir); \
		ln -s ../$(Yaml_lib_debug_src) $(Yaml_lib_debug_dest); \
		echo "YAML调试版静态库链接创建完成"; \
	else \
		echo "YAML调试版静态库链接已存在"; \
	fi

# 检查 yaml 发布版静态库和头文件是否链接
.PHONY : check-yaml-release
check-yaml-release :
	@echo "构建YAML发布版模块"
	@$(MAKE) -C $(Yaml_builder_dir) static-lib

	@echo "检查YAML发布版静态库及头文件链接..."
	@# 检查头文件目录链接是否存在
	@if [ ! -e "$(Yaml_include_dest)" ]; then \
		mkdir -p $(Include); \
		ln -s ../$(Yaml_include_src) $(Yaml_include_dest); \
		echo "YAML头文件链接创建完成"; \
	else \
		echo "YAML头文件目录链接已存在"; \
	fi
	@# 检查发布版静态库链接是否存在
	@if [ ! -e "$(Yaml_lib_release_dest)" ]; then \
		mkdir -p $(Lib_dir); \
		ln -s ../$(Yaml_lib_release_src) $(Yaml_lib_release_dest); \
		echo "YAML发布版静态库链接创建完成"; \
	else \
		echo "YAML发布版静态库链接已存在"; \
	fi

# 保留兼容旧流程的总检查任务
.PHONY : check-yaml
check-yaml : check-yaml-debug check-yaml-release
	@echo "YAML库链接检查完成"

# 清理 yaml 构建文件（调用子模块的清理目标）
.PHONY : clean-yaml
clean-yaml :
	@echo "正在清理 YAML 构建文件..."
	@$(MAKE) -C $(Yaml_builder_dir) clean
	@if [ -L "$(Yaml_include_dest)" ]; then \
		rm -f $(Yaml_include_dest); \
		echo "已删除 $(Yaml_include_dest) 链接"; \
	fi
	@if [ -L "$(Yaml_lib_debug_dest)" ]; then \
		rm -f $(Yaml_lib_debug_dest); \
		echo "已删除 $(Yaml_lib_debug_dest) 链接"; \
	fi
	@if [ -L "$(Yaml_lib_release_dest)" ]; then \
		rm -f $(Yaml_lib_release_dest); \
		echo "已删除 $(Yaml_lib_release_dest) 链接"; \
	fi
	@echo "YAML 构建文件清理完成！"

# ====== 示例程序目标 ======

# yaml_to_json 目标文件（供示例程序使用）
.PHONY : yaml_to_json_obj
yaml_to_json_obj : build/yaml_to_json.o
	@echo "确保 yaml_to_json.o 已构建完成"

# 调用example目录中的Makefile
.PHONY : example
example : yaml_to_json_obj
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
clean-all : clean
	@echo "全部清理完成！"