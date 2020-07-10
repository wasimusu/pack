cmake_minimum_required(VERSION 3.10)
project(pack)

set(CMAKE_CXX_STANDARD 11)

# Add the cmake folder so the FindSphinx module is found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
add_subdirectory(src)

add_subdirectory(test/googletest)
include_directories(test/googletest/googletest/include)

add_executable(sample_test test/pack_test.cpp)
add_executable(tests test/pack_test.cpp test/test_main.cpp)

target_link_libraries(sample_test gtest gtest_main)
target_link_libraries(tests gtest gtest_main)
