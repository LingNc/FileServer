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

# 如果没有创建就创建build
$(shell mkdir -p build)
$(shell mkdir -p $(Ext))
$(shell mkdir -p $(Lib_dir))

# 构建 main
main : $(Obj) | link
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
	@echo "正在链接库文件..."
	@if [ ! -e ./$(Include)/loglib.hpp ]; then \
		ln -s ../module/loglib/loglib.hpp ./$(Include)/loglib.hpp; \
		echo "链接创建完成！"; \
	else \
		echo "链接已存在，跳过创建"; \
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
	fi
	@echo "YAML 仓库清理完成！"

# 清理
.PHONY : clean
clean :
	@echo "正在清理..."
	rm -f build/*.o main
	clean-yaml-git
	@echo "清理完成！"

# 全部清理（包括 YAML）
.PHONY : clean-all
clean-all : clean clean-yaml
	@echo "全部清理完成！"