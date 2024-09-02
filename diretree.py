#!/bin/bash

# Function to build the directory tree
build_tree() {
    local dir="$1"
    local level="$2"

    # Indentation for current level
    local indent=""
    for ((i = 0; i < level; i++)); do
        indent+="  "
    done

    # List directories and files
    local entries
    entries=$(ls -A "$dir")
    for entry in $entries; do
        local entry_path="$dir/$entry"
        if [ -d "$entry_path" ]; then
            echo "${indent}[DIR] $entry"
            build_tree "$entry_path" $((level + 1))
        else
            echo "${indent}  $entry"
        fi
    done
}

# Entry point
if [ -z "$1" ]; then
    echo "Usage: $0 <root-directory>"
    exit 1
fi

root_directory="$1"
if [ ! -d "$root_directory" ]; then
    echo "Error: '$root_directory' is not a valid directory."
    exit 1
fi

# Generate tree structure and save to file
tree_structure=$(build_tree "$root_directory" 0)
output_file="directory_tree.txt"
echo "$tree_structure" > "$output_file"

echo "Directory tree has been saved to $output_file."
