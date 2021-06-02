
cmake_minimum_required(VERSION 3.16)

project(NanoBS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

FILE(GLOB_RECURSE SRCS "src/*.cpp")


include_directories(include)
add_subdirectory(tests)

add_test(NAME testss COMMAND test_criterion)

add_executable(nanotekspice ${SRCS} main.cpp)