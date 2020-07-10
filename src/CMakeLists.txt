set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.10)

add_library(pack_lib "boundingBox.h" "pack.cpp")
target_include_directories(pack_lib PUBLIC .)
set_target_properties(pack_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main main.cpp)
target_link_libraries(main pack_lib)