cmake_minimum_required(VERSION 3.10)
project(pack)

set(CMAKE_CXX_STANDARD 11)

# Add the cmake folder so the FindSphinx module is found
add_subdirectory(src)
add_subdirectory(test)
