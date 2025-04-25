# 编译器设置
Cpp = g++
Cpp_flags = -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG

# 头文件
Include = include

# 构建 main
main : copy build/main.o
	@echo "正在链接..."
	$(Cpp) $(Cpp_flags) -o $@ $^
	@echo "构建完成！"

build/main.o : src/main.cpp
	@echo "正在编译 $< ..."
	$(Cpp) $(Cpp_flags) -c $< -o $@ -I$(Include)
	@echo "编译完成！"

# 复制子模块的头文件到include位置
.PHONY : link
link :
	@echo "正在复制库文件..."
	ln -s ../module/loglib/loglib.hpp ./$(Include)/loglib.hpp
	@echo "复制完成！"

# 清理
.PHONY : clean
clean :
	@echo "正在清理..."
	rm -f build/*.o main
	@echo "清理完成！"