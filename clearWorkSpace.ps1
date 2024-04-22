$directory = Get-Location
$files = Get-ChildItem -Path $directory -Recurse -Filter "*.exe"

if ($files.Count -eq 0) {
    Write-Host "No .exe files found to remove."
} else {
    $files | ForEach-Object {
        $file_path = $_.FullName
        Remove-Item -Path $file_path -Force
        Write-Host "Removed file: $file_path"
    }
}