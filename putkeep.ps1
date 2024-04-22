Get-ChildItem -Directory -Recurse | ForEach-Object {
    $gitKeepPath = Join-Path $_.FullName ".gitkeep"
    New-Item -ItemType File -Path $gitKeepPath -Force
}