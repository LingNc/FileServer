#!/bin/bash

# 检查是否以 root 用户运行
if [ "$EUID" -ne 0 ]; then
  echo "请以 root 用户运行此脚本"
  exit 1
fi

# 定义源文件和目标文件
SOURCE_FILE="zerofile.cpp"
TARGET_FILE="zerofile"

# 检查源文件是否存在
if [ ! -f "$SOURCE_FILE" ]; then
  echo "源文件 $SOURCE_FILE 不存在"
  exit 1
fi

# 编译 C++ 文件
echo "正在编译 $SOURCE_FILE..."
g++ -o "$TARGET_FILE" "$SOURCE_FILE" -pthread


# 检查编译是否成功
if [ $? -ne 0 ]; then
  echo "编译失败"
  exit 1
fi

if [ ! -d "/opt/zerofile" ]; then
  mkdir /opt/zerofile
fi

# 将生成的可执行文件移动到 /opt/zerofile
echo "正在安装 $TARGET_FILE 到 /opt/zerofile..."
mv "$TARGET_FILE" /opt/zerofile/$TARGET_FILE

if [ ! -d "/opt/zerofile/dist" ]; then
  mkdir /opt/zerofile/dist
fi
if [ ! -d "/opt/zerofile/config" ]; then
  mkdir /opt/zerofile/config
fi
#mkdir /opt/zerofile/dist /opt/zerofile/config 2>&1

cp ../planet /opt/zerofile/dist/planet

#安装服务文件
cp service/zerofile.service /etc/systemd/system/zerofile.service
systemctl daemon-reload
systemctl restart zerofile

echo "安装结束"
