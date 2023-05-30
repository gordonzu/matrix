#!/bin/bash

rm -rf build 
mkdir build && cd build 
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && 
make all  
rm -rf ../compile_commands.json
ln -s compile_commands.json ../.
#./tests/unit_tests/unit_tests_run

