#!/bin/bash
cpp_args="-pipe -Wunused-variable -fvisibility=hidden -funsigned-char -fstack-protector"
debug_cfg="-Ddebug=true -Doptimization=0 -Dwarning_level=3"

if [[ -z "${MSYSTEM}" ]]; then
debug_cfg="$debug_cfg -Db_sanitize=address"
fi

echo "cpp_args: $cpp_args"
echo "debug_cfg: $debug_cfg"

meson setup --reconfigure build $debug_cfg -Dcpp_args="$cpp_args"
