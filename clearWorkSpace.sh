directory=$(pwd)
files=$(find "$directory" -type f -name "*.exec")

if [ -z "$files" ]; then
    echo "No .exec files found to remove."
else
    for file_path in $files; do
        rm -f "$file_path"
        echo "Removed file: $file_path"
    done
fi