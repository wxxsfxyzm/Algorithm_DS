#!/bin/bash

# 遍历当前目录及所有子目录
find . -type d | while read dir; do
    # 构建.gitkeep文件的路径
    gitKeepPath="$dir/.gitkeep"
    
    # 获取除.gitkeep外的文件和子目录数量
    count=$(find "$dir" -mindepth 1 -maxdepth 1 ! -name ".gitkeep" | wc -l)
    
    # 如果目录为空或只有.gitkeep文件
    if [ "$count" -eq 0 ]; then
        # 如果.gitkeep文件不存在，则创建它
        if [ ! -f "$gitKeepPath" ]; then
            touch "$gitKeepPath"
        fi
    else
        # 如果目录不为空且.gitkeep文件存在，则删除它
        if [ -f "$gitKeepPath" ]; then
            rm "$gitKeepPath"
        fi
    fi
done