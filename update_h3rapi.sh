#!/bin/bash
h3rapi="inst/include/h3rapi.h"
input_file="src/h3r.h"

# Extract function names and arguments together
func_arg_pairs=$(sed -n -E 's/SEXP ([a-zA-Z0-9_]+)\((.*)\);/\1|\2/p' "$input_file")

# Convert to an array
IFS=$'\n' read -d '' -ra func_arg_arr <<< "$func_arg_pairs"

output=""

for pair in "${func_arg_arr[@]}"; do
    # Split function name and arguments using '|' as the delimiter
    IFS='|' read -ra func_arg <<< "$pair"
    func="${func_arg[0]}"
    arg="${func_arg[1]}"

    arg_name=$(echo "$arg" | sed -E 's/([a-zA-Z0-9_]+) ([a-zA-Z0-9_]+)/\2/g')

    echo "func: $func"
    echo "arg: $arg_name"
    output+=""
done

temp_output=$(mktemp)

echo "$output" > "$temp_output"

echo -e "\ndifferences:"
diff "$temp_output" "$input_file"


echo -e "\nInstall the update? (y/n)"
read -r answer
case $answer in
    [Nn]* )
        echo "Quitting..."; 
        exit
    ;;
    [Yy]* )
        echo -e "$output" > "$h3rapi"
        echo "Finished update"
    ;;
    * ) echo "Invalid input";;
esac