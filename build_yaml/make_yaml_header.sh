#!/bin/bash
set -e

#====== 配置部分 ======
# 版本信息
VERSION="1.0.0"                   # 版本号

# 目录配置
YAML_SRC="yaml-cpp"               # YAML-CPP 源码目录
TEMP_DIR="temp"                   # 临时文件目录
EXT_DIR="ext"                     # 扩展库目录（存放头文件）
LIB_DIR="lib"                     # 库文件目录（存放静态库）

# 文件名配置
HEADER_FILE="yaml.hpp"           # 合并后的头文件名
LIB_FILE="libyaml.a"             # 静态库文件名
DEBUG_LIB_FILE="libyaml-debug.a" # 调试版静态库文件名

# 构建配置
YAML_BUILD="${YAML_SRC}/build"    # 构建目录
YAML_DEBUG_BUILD="${YAML_SRC}/build-debug" # 调试版构建目录
YAML_LIB="libyaml-cpp.a"          # 构建生成的原始静态库名

# 检查是否需要构建调试版本
BUILD_DEBUG=true
if [ "$1" == "--no-debug" ]; then
    BUILD_DEBUG=false
fi

# 获取构建信息
BUILD_DATE=$(date "+%Y-%m-%d %H:%M:%S")
BUILD_OS=$(uname -a)
if [ -f "${YAML_SRC}/CMakeLists.txt" ]; then
    YAML_VERSION=$(grep -oP 'project\(YAML_CPP VERSION \K[0-9\.]+' "${YAML_SRC}/CMakeLists.txt" || echo "unknown")
else
    YAML_VERSION="unknown"
fi

# 搜索路径配置
SEARCH_PATHS=(
    "${TEMP_DIR}"
    "${YAML_SRC}/include"
    "${YAML_SRC}/include/yaml-cpp"
    "${YAML_SRC}/include/yaml-cpp/contrib"
    "${YAML_SRC}/include/yaml-cpp/node"
    "${YAML_SRC}/include/yaml-cpp/node/detail"
    "${TEMP_DIR}/yaml-cpp"
    "${TEMP_DIR}/yaml-cpp/contrib"
    "${TEMP_DIR}/yaml-cpp/node"
    "${TEMP_DIR}/yaml-cpp/node/detail"
)

# 输出文件路径
OUT="${EXT_DIR}/${HEADER_FILE}"
#====== 配置结束 ======

echo "===== 开始构建 yaml-cpp 头文件和静态库 ====="
echo "源码目录: ${YAML_SRC}"
echo "头文件输出: ${EXT_DIR}/${HEADER_FILE}"
echo "静态库输出: ${LIB_DIR}/${LIB_FILE}"
if [ "$BUILD_DEBUG" = true ]; then
    echo "调试版静态库输出: ${LIB_DIR}/${DEBUG_LIB_FILE}"
fi
echo "版本: ${VERSION} (原版 YAML-CPP: ${YAML_VERSION})"
echo "构建日期: ${BUILD_DATE}"
echo "构建系统: ${BUILD_OS}"

# 确保目录存在
mkdir -p "${EXT_DIR}"
mkdir -p "${LIB_DIR}"

# 第1步：生成合并的头文件
echo "正在生成合并头文件 ${OUT}..."
> "$OUT"
echo "// Auto-generated amalgamated yaml-cpp header-only file" >> "$OUT"
echo "// 版本: ${VERSION} (原版 YAML-CPP: ${YAML_VERSION})" >> "$OUT"
echo "// 构建日期: ${BUILD_DATE}" >> "$OUT"
echo "// 构建系统: ${BUILD_OS}" >> "$OUT"
echo "// 注意: 此文件只包含头文件，需要配合 ${LIB_FILE} 静态库使用" >> "$OUT"
echo "#pragma once" >> "$OUT"

# 记录已处理文件，避免重复递归
declare -A included

# 查找头文件的函数
find_include() {
    local inc="$1"

    # 直接路径
    if [[ -f "$inc" ]]; then
        echo "$inc"
        return 0
    fi

    # 遍历所有搜索路径
    for path in "${SEARCH_PATHS[@]}"; do
        if [[ -f "$path/$inc" ]]; then
            echo "$path/$inc"
            return 0
        fi
    done

    # 特殊处理 yaml-cpp/ 开头的
    if [[ "$inc" == yaml-cpp/* ]]; then
        local subinc="${inc#yaml-cpp/}"
        for path in "${SEARCH_PATHS[@]}"; do
            if [[ -f "$path/$subinc" ]]; then
                echo "$path/$subinc"
                return 0
            fi
        done
    fi

    # 未找到
    echo ""
    return 1
}

# 递归展开 include 的函数
expand_file() {
    local file="$1"
    # 绝对路径去重
    local absfile="$(readlink -f "$file")"
    if [[ -n "${included[$absfile]}" ]]; then
        return
    fi
    included[$absfile]=1

    echo -e "\n// ====== BEGIN $file ======" >> "$OUT"

    while IFS= read -r line; do
        # 匹配 #include "xxx.h" 的各种形式
        if [[ "$line" =~ ^#include\ \"([^\"]+)\" ]]; then
            local incfile="${BASH_REMATCH[1]}"

            # 跳过源码中的内部引用
            if [[ "$incfile" == *graphbuilderadapter.h || \
                  "$incfile" == *ptr_vector.h || \
                  "$incfile" == *collectionstack.h || \
                  "$incfile" == *directives.h || \
                  "$incfile" == *emitterstate.h || \
                  "$incfile" == *emitterutils.h || \
                  "$incfile" == *exp.h || \
                  "$incfile" == *indentation.h || \
                  "$incfile" == *nodebuilder.h || \
                  "$incfile" == *nodeevents.h || \
                  "$incfile" == *regex_yaml.h || \
                  "$incfile" == *regeximpl.h || \
                  "$incfile" == *scanner.h || \
                  "$incfile" == *scanscalar.h || \
                  "$incfile" == *scantag.h || \
                  "$incfile" == *setting.h || \
                  "$incfile" == *singledocparser.h || \
                  "$incfile" == *stream.h || \
                  "$incfile" == *streamcharsource.h || \
                  "$incfile" == *stringsource.h || \
                  "$incfile" == *tag.h || \
                  "$incfile" == *token.h ]]; then
                echo "// 跳过内部头文件: $incfile" >> "$OUT"
                continue
            fi

            local fullpath=$(find_include "$incfile")

            if [[ -n "$fullpath" ]]; then
                echo "// 展开 include: $incfile" >> "$OUT"
                expand_file "$fullpath"
            else
                # 如果找不到，保留原始 include
                echo "// [警告] 未找到: $incfile" >> "$OUT"
                echo "$line" >> "$OUT"
            fi
        # 保留标准库和系统头文件
        elif [[ "$line" =~ ^#include\ \<.*\> ]]; then
            echo "$line" >> "$OUT"
        else
            echo "$line" >> "$OUT"
        fi
    done < "$file"

    echo -e "// ====== END $file ======\n" >> "$OUT"
}

echo -e "\n// ====== 头文件开始 ======" >> "$OUT"
# 先展开 yaml.h（作为入口头文件）
if [[ -f "${TEMP_DIR}/yaml.h" ]]; then
    echo "使用 ${TEMP_DIR}/yaml.h 作为入口..."
    expand_file "${TEMP_DIR}/yaml.h"
elif [[ -f "${YAML_SRC}/include/yaml-cpp/yaml.h" ]]; then
    echo "使用 ${YAML_SRC}/include/yaml-cpp/yaml.h 作为入口..."
    expand_file "${YAML_SRC}/include/yaml-cpp/yaml.h"
else
    echo "错误: 找不到 yaml.h 入口文件!"
    exit 1
fi

echo "已生成合并头文件: $OUT"
echo "检查未能展开的 include:"
grep -n "未找到" "$OUT" || echo "全部头文件展开成功!"

# 第2步：编译标准静态库
echo "===== 开始编译 yaml-cpp 静态库 ====="
mkdir -p ${YAML_BUILD}
cd ${YAML_BUILD}

# 配置构建（只生成静态库，不生成动态库和测试）
echo "配置 CMake 构建..."
cmake -DYAML_BUILD_SHARED_LIBS=OFF -DYAML_CPP_BUILD_TESTS=OFF -DYAML_CPP_BUILD_TOOLS=OFF ..

# 编译库
echo "编译 yaml-cpp 静态库..."
make -j$(nproc)

# 复制静态库到 lib 目录
cd ../..
echo "复制静态库到 ${LIB_DIR}/${LIB_FILE}..."
cp "${YAML_BUILD}/${YAML_LIB}" "${LIB_DIR}/${LIB_FILE}"

# 第3步：如果需要，编译调试版静态库
if [ "$BUILD_DEBUG" = true ]; then
    echo "===== 开始编译 yaml-cpp 调试版静态库 ====="
    mkdir -p ${YAML_DEBUG_BUILD}
    cd ${YAML_DEBUG_BUILD}

    # 配置构建（启用调试标志）
    echo "配置 CMake 调试版构建..."
    cmake -DYAML_BUILD_SHARED_LIBS=OFF -DYAML_CPP_BUILD_TESTS=OFF -DYAML_CPP_BUILD_TOOLS=OFF -DCMAKE_CXX_FLAGS="-D_GLIBCXX_DEBUG" ..

    # 编译库
    echo "编译 yaml-cpp 调试版静态库..."
    make -j$(nproc)

    # 复制静态库到 lib 目录
    cd ../..
    echo "复制调试版静态库到 ${LIB_DIR}/${DEBUG_LIB_FILE}..."
    cp "${YAML_DEBUG_BUILD}/${YAML_LIB}" "${LIB_DIR}/${DEBUG_LIB_FILE}"
fi

echo "===== 构建完成 ====="
echo "头文件: ${EXT_DIR}/${HEADER_FILE}"
echo "静态库: ${LIB_DIR}/${LIB_FILE}"
if [ "$BUILD_DEBUG" = true ]; then
    echo "调试版静态库: ${LIB_DIR}/${DEBUG_LIB_FILE}"
    echo "使用方法: #include \"${HEADER_FILE}\" 并链接 ${LIB_FILE} (普通版) 或 ${DEBUG_LIB_FILE} (调试版)"
else
    echo "使用方法: #include \"${HEADER_FILE}\" 并链接 ${LIB_FILE}"
fi