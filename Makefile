# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG  # 开发环境编译选项
Cpp_flags_release = -std=c++17 -Wall -Wextra -O3 -DNDEBUG  # 生产环境编译选项

# 源文件和目标文件
Src = src/main.cpp src/yaml_to_json.cpp
Obj = $(patsubst src/%.cpp,build/%.o,$(Src))
Obj_release = $(patsubst src/%.cpp,build/%_release.o,$(Src))
# 使用单头文件版本的目标文件
Obj_merged = $(patsubst src/%.cpp,build/%_merged.o,$(Src))
Obj_merged_release = $(patsubst src/%.cpp,build/%_merged_release.o,$(Src))

# YAML 相关配置
YAML_REPO = yaml-cpp
YAML_GIT = https://github.com/jbeder/yaml-cpp.git
YAML_BUILD_DIR = build_yaml
YAML_HEADER_SCRIPT = $(YAML_BUILD_DIR)/make_yaml_header.sh
YAML_ALL_SCRIPT = $(YAML_BUILD_DIR)/make_yaml_all.sh

# 链接静态库（开发版本使用调试库，生产版本使用标准库）
Lib = lib/libyaml-debug.a
Lib_release = lib/libyaml.a

# 头文件
Include = include
Ext = ext
Lib_dir = lib

# YAML库类型标志（通过-D宏定义区分两种使用方式）
YAML_FLAGS_STATIC = -DUSE_YAML_STATIC_LIB  # 使用静态库版本
YAML_FLAGS_MERGED = -DUSE_YAML_MERGED_HEADER  # 使用合并单头文件版本

# 如果没有创建就创建build和example目录
$(shell mkdir -p build)
$(shell mkdir -p $(Ext))
$(shell mkdir -p $(Lib_dir))
$(shell mkdir -p example)

# ====== main 主程序构建 ======

# 构建 main（开发版本，带调试功能，使用静态库）
main : $(Obj) | link check-yaml
	@echo "正在链接开发版本（带调试功能，使用静态库版YAML）..."
	$(Cpp) $(Cpp_flags) -o $@ $^ $(Lib)
	@echo "开发版本构建完成！"

# 构建 main-release（生产版本，优化性能，使用静态库）
main-release : $(Obj_release) | link check-yaml
	@echo "正在链接生产版本（优化性能，使用静态库版YAML）..."
	$(Cpp) $(Cpp_flags_release) -o $@ $^ $(Lib_release)
	@echo "生产版本构建完成！"

# 构建 main-merged（开发版本，带调试功能，使用合并单头文件）
main-merged : $(Obj_merged) | link check-yaml-all
	@echo "正在链接开发版本（带调试功能，使用合并单头文件版YAML）..."
	$(Cpp) $(Cpp_flags) -o $@ $^
	@echo "开发版本(合并头文件)构建完成！"

# 构建 main-merged-release（生产版本，优化性能，使用合并单头文件）
main-merged-release : $(Obj_merged_release) | link check-yaml-all
	@echo "正在链接生产版本（优化性能，使用合并单头文件版YAML）..."
	$(Cpp) $(Cpp_flags_release) -o $@ $^
	@echo "生产版本(合并头文件)构建完成！"

# 通用规则：编译所有源文件（开发版本，使用静态库）
build/%.o : src/%.cpp
	@echo "正在编译 $< (开发版本，使用静态库版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags) $(YAML_FLAGS_STATIC) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 通用规则：编译所有源文件（生产版本，使用静态库）
build/%_release.o : src/%.cpp
	@echo "正在编译 $< (生产版本，使用静态库版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags_release) $(YAML_FLAGS_STATIC) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 通用规则：编译所有源文件（开发版本，使用合并单头文件）
build/%_merged.o : src/%.cpp
	@echo "正在编译 $< (开发版本，使用合并单头文件版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags) $(YAML_FLAGS_MERGED) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 通用规则：编译所有源文件（生产版本，使用合并单头文件）
build/%_merged_release.o : src/%.cpp
	@echo "正在编译 $< (生产版本，使用合并单头文件版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags_release) $(YAML_FLAGS_MERGED) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 特殊规则：编译yaml_to_json.cpp时不使用_GLIBCXX_DEBUG标志（静态库版）
build/yaml_to_json.o : src/yaml_to_json.cpp
	@echo "正在编译 $< (开发版本，无调试标志，使用静态库版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) -std=c++17 -Wall -Wextra -g $(YAML_FLAGS_STATIC) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 特殊规则：编译yaml_to_json.cpp（生产版本，静态库版）
build/yaml_to_json_release.o : src/yaml_to_json.cpp
	@echo "正在编译 $< (生产版本，使用静态库版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags_release) $(YAML_FLAGS_STATIC) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 特殊规则：编译yaml_to_json.cpp时不使用_GLIBCXX_DEBUG标志（合并单头文件版）
build/yaml_to_json_merged.o : src/yaml_to_json.cpp
	@echo "正在编译 $< (开发版本，无调试标志，使用合并单头文件版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) -std=c++17 -Wall -Wextra -g $(YAML_FLAGS_MERGED) -c $< -o $@ -I$(Include) -I$(Ext)
	@echo "编译完成 $@ ！"

# 特殊规则：编译yaml_to_json.cpp（生产版本，合并单头文件版）
build/yaml_to_json_merged_release.o : src/yaml_to_json.cpp
	@echo "正在编译 $< (生产版本，使用合并单头文件版YAML)..."
	@mkdir -p $(dir $@)
	$(Cpp) $(Cpp_flags_release) $(YAML_FLAGS_MERGED) -c $< -o $@ -I$(Include) -I$(Ext)
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
	elif [ ! -f "$(Lib_dir)/libyaml-debug.a" ]; then \
		echo "YAML调试库文件不存在，需要生成"; \
		$(MAKE) yaml_header; \
	else \
		echo "YAML头文件和库已存在，跳过生成"; \
	fi

# 检查 yaml-cpp.hpp 是否存在（合并单头文件版）
.PHONY : check-yaml-all
check-yaml-all :
	@echo "检查YAML合并单头文件是否存在..."
	@if [ ! -f "$(Ext)/yaml-cpp.hpp" ]; then \
		echo "YAML合并单头文件不存在，需要生成"; \
		$(MAKE) yaml_all; \
	else \
		echo "YAML合并单头文件已存在，跳过生成"; \
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
	@echo "正在生成 yaml.hpp 单头文件和静态库(含调试版)..."
	@chmod +x $(YAML_HEADER_SCRIPT)
	@./$(YAML_HEADER_SCRIPT)
	@echo "yaml.hpp 和静态库生成完成！"

# 生成单一头文件版 yaml.hpp（不含调试版库）
.PHONY : yaml_header_no_debug
yaml_header_no_debug : check-yaml-repo
	@echo "正在生成 yaml.hpp 单头文件和静态库(不含调试版)..."
	@chmod +x $(YAML_HEADER_SCRIPT)
	@./$(YAML_HEADER_SCRIPT) --no-debug
	@echo "yaml.hpp 和静态库生成完成！"

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

# ====== 示例程序目标 ======

# yaml_to_json 目标文件（供示例程序使用，静态库版）
.PHONY : yaml_to_json_obj
yaml_to_json_obj : build/yaml_to_json.o
	@echo "确保 yaml_to_json.o 已构建完成"

# yaml_to_json 目标文件（供示例程序使用，合并单头文件版）
.PHONY : yaml_to_json_merged_obj
yaml_to_json_merged_obj : build/yaml_to_json_merged.o
	@echo "确保 yaml_to_json_merged.o 已构建完成"

# 调用example目录中的Makefile（使用静态库版）
.PHONY : example
example : yaml_to_json_obj check-yaml
	@echo "正在调用example目录的Makefile构建示例程序（静态库版）..."
	$(MAKE) -C example YAML_TYPE=static example

# 调用example目录中的Makefile（使用合并单头文件版）
.PHONY : example-merged
example-merged : yaml_to_json_merged_obj check-yaml-all
	@echo "正在调用example目录的Makefile构建示例程序（合并单头文件版）..."
	$(MAKE) -C example YAML_TYPE=merged example

# 运行示例程序（静态库版）
.PHONY : run-example
run-example : example
	@echo "正在调用example目录的Makefile运行示例程序（静态库版）..."
	$(MAKE) -C example YAML_TYPE=static run-example

# 运行示例程序（合并单头文件版）
.PHONY : run-example-merged
run-example-merged : example-merged
	@echo "正在调用example目录的Makefile运行示例程序（合并单头文件版）..."
	$(MAKE) -C example YAML_TYPE=merged run-example

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
	@echo "【静态库版本】"
	@echo "make             - 构建主程序（开发版本，带调试功能，使用静态库版YAML）"
	@echo "make main        - 构建主程序（开发版本，带调试功能，使用静态库版YAML）"
	@echo "make main-release- 构建主程序（生产版本，优化性能，使用静态库版YAML）"
	@echo "【合并单头文件版本】"
	@echo "make main-merged - 构建主程序（开发版本，带调试功能，使用合并单头文件版YAML）"
	@echo "make main-merged-release - 构建主程序（生产版本，优化性能，使用合并单头文件版YAML）"
	@echo "【示例程序】"
	@echo "make example     - 构建YAML-JSON示例程序（静态库版）"
	@echo "make example-merged - 构建YAML-JSON示例程序（合并单头文件版）"
	@echo "make run-example - 运行YAML-JSON示例程序（静态库版）"
	@echo "make run-example-merged - 运行YAML-JSON示例程序（合并单头文件版）"
	@echo "make direct-test - 构建直接使用YAML-CPP的测试程序"
	@echo "make run-direct-test - 运行直接使用YAML-CPP的测试程序"
	@echo "【清理】"
	@echo "make clean       - 清理构建文件"
	@echo "make clean-all   - 清理所有文件，包括YAML库"
	@echo "【YAML库】"
	@echo "make yaml_header - 生成yaml.hpp单头文件+静态库(含调试版)"
	@echo "make yaml_header_no_debug - 生成yaml.hpp单头文件+静态库(不含调试版)"
	@echo "make yaml_all    - 生成yaml-cpp.hpp全合并版"
	@echo "make clean-yaml  - 清理YAML构建文件"
	@echo "make clean-yaml-git - 清理YAML仓库"
	@echo "make help        - 显示此帮助信息"

# 清理
.PHONY : clean
clean :
	@echo "正在清理..."
	rm -f build/*.o build/*_release.o build/*_merged.o build/*_merged_release.o main main-release main-merged main-merged-release
	$(MAKE) -C example clean
	@echo "清理完成！"

# 全部清理（包括 YAML）
.PHONY : clean-all
clean-all : clean clean-yaml
	@echo "全部清理完成！"