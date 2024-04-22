Get-ChildItem -Directory -Recurse | ForEach-Object {
    $gitKeepPath = Join-Path $_.FullName ".gitkeep"
    # 获取当前目录下所有文件和子目录，不排除任何项
    $childItems = Get-ChildItem -Path $_.FullName
    
    # 检查目录是否真的为空（即没有文件也没有子目录）
    if ($childItems.Count -eq 0 -or ($childItems.Count -eq 1 -and $childItems.Name -eq ".gitkeep")) {
        # 如果目录为空或只有.gitkeep，则确保.gitkeep存在
        if (-not (Test-Path $gitKeepPath)) {
            New-Item -ItemType File -Path $gitKeepPath -Force
        }
    } else {
        # 如果目录不为空，则确保移除.gitkeep（如果存在）
        if (Test-Path $gitKeepPath) {
            Remove-Item -Path $gitKeepPath -Force
        }
    }
}