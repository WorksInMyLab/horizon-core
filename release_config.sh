#!/bin/bash
cpp_args="-pipe -Wunused-variable -fvisibility=hidden -funsigned-char -fstack-protector"
release_cfg="-Ddebug=false -Doptimization=2 -Dwarning_level=2 -Db_sanitize=none"

meson setup --reconfigure build $release_cfg -Dcpp_args="$cpp_args"
