project(test_pack)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(sample_test pack_test.cpp)
add_executable(tests pack_test.cpp test_main.cpp)

target_link_libraries(sample_test gtest gtest_main)
target_link_libraries(tests gtest gtest_main)