$directory = "C:\Users\Carl Yu\VS Code\Algorithm_DS"
$files = Get-ChildItem -Path $directory -Recurse -Filter "*.exec"

if ($files.Count -eq 0) {
    Write-Host "No .exec files found to remove."
} else {
    $files | ForEach-Object {
        $file_path = $_.FullName
        Remove-Item -Path $file_path -Force
        Write-Host "Removed file: $file_path"
    }
}