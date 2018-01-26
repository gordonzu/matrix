project(matrix)
cmake_minimum_required(VERSION 2.6)

include_directories("/home/gordonzu/src/cpp/matrixamic_cast")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -O0 -fmax-errors=1")

set(sources
    object.cpp
    agent.cpp
    xy_location.cpp
    matrix.cpp
    main.cpp
    )

add_executable(matrix ${sources})

add_custom_command(TARGET matrix 
                   POST_BUILD
                   COMMAND "make")

add_custom_command(TARGET matrix
                   POST_BUILD
                   COMMAND valgrind --tool=memcheck --leak-check=yes ./matrix)
#                 COMMAND "matrix")

