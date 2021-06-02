cmake_minimum_required(VERSION 3.16)
 
set(PROJECT_ROOT "..")
set(SOURCE_ROOT "${PROJECT_ROOT}/src")

FILE(GLOB TEST_SRCS "*.cpp")

include_directories(
    ${PROJECT_ROOT}/include
)

add_executable(test_criterion ${TEST_SRCS} ${SRCS})

target_link_libraries(test_criterion
    criterion
)