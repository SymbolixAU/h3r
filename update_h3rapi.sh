#!/bin/bash
h3rapi="inst/include/h3rapi.h"
input_file="src/h3r.h"

# Extract function names and arguments together
func_arg_pairs=$(sed -n -E 's/^SEXP ([a-zA-Z0-9_]+)\((.*)\);/\1|\2/p' "$input_file")

# Convert to an array
IFS=$'\n' read -d '' -ra func_arg_arr <<< "$func_arg_pairs"

output="
#ifndef R_H3R_API_H
#define R_H3R_API_H

#include <R.h>
#include <Rinternals.h>
#include <Rconfig.h>
#include <R_ext/Rdynload.h>

#ifdef HAVE_VISIBILITY_ATTRIBUTE
# define attribute_hidden __attribute__ ((visibility ("hidden")))
#else
# define attribute_hidden
#endif

#ifdef __cplusplus
extern \"C\" {
#endif
  "

for pair in "${func_arg_arr[@]}"; do
    # Split function name and arguments using '|' as the delimiter
    IFS='|' read -ra func_arg <<< "$pair"
    func="${func_arg[0]}"
    arg="${func_arg[1]}"

    arg_name=$(echo "$arg" | sed -E 's/([a-zA-Z0-9_]+) ([a-zA-Z0-9_]+)/\2/g')
    arg_type=$(echo "$arg" | sed -E 's/([a-zA-Z0-9_]+) ([a-zA-Z0-9_]+)/\1/g')

    output+="inline SEXP attribute_hidden ${func}(${arg}) {
    SEXP(*fun)(${arg_type}) =
      (SEXP(*)(${arg_type})) R_GetCCallable(\"h3r\", \"${func}\");
    return fun(${arg_name});
  }
  "
done

output+="#ifdef __cplusplus
}


namespace h3r {
  "

for pair in "${func_arg_arr[@]}"; do
    # Split function name and arguments using '|' as the delimiter
    IFS='|' read -ra func_arg <<< "$pair"
    func="${func_arg[0]}"
    arg="${func_arg[1]}"

    without_h3r="${func#h3r}"
    first_char="$(echo "${without_h3r:0:1}" | tr '[:upper:]' '[:lower:]')"
    rest="${without_h3r:1}"
    func_modified="${first_char}${rest}"

    arg_name=$(echo "$arg" | sed -E 's/([a-zA-Z0-9_]+) ([a-zA-Z0-9_]+)/\2/g')

    output+="  inline SEXP ${func_modified}(${arg}) {
    return ${func}(${arg_name});
  }
  "
done

output+="
}


#endif  // __cplusplus

#endif // R_H3R_API_H"

temp_output=$(mktemp)

echo "$output" > "$temp_output"

echo -e "\ndifferences:"
diff "$temp_output" "$h3rapi"


echo -e "\nInstall the update? (y/n)"
read -r answer
case $answer in
    [Nn]* )
        echo "Quitting..."; exit;;
    [Yy]* )
        echo -e "$output" > "$h3rapi"
        echo "Finished update"
    ;;
    * ) echo "Invalid input";;
esac
