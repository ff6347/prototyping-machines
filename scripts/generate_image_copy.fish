#!/usr/bin/env fish

# Define the image extensions we're looking for
set image_extensions "png" "jpg" "jpeg" "gif"

# Find all directories containing image files
set image_dirs (find . -type f \( -name "*.png" -o -name "*.jpg" -o -name "*.jpeg" -o -name "*.gif" \) | xargs -n1 dirname | sort -u)

# Print the JavaScript comments
echo "// Copy images from specific directories"

# Generate and print the addPassthroughCopy statements
for dir in $image_dirs
    # Remove the leading "./" from the directory path
    set clean_dir (echo $dir | sed 's/^\.\///')

    # Generate the file pattern for all image types
    set file_pattern (string join "," $image_extensions | sed 's/,/,*/g')

    # Print the addPassthroughCopy statement
    echo "eleventyConfig.addPassthroughCopy(\"$clean_dir/**/*.{$file_pattern}\");"
end
