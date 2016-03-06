cmake_minimum_required(VERSION 2.8.0)

file(GLOB gem_test_SRC
        src/gem/*cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

################################
# GTest
################################
# ADD_SUBDIRECTORY (test)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ../lib ../game)

################################
# Unit Tests
################################
add_executable(runUnitTests ${gem_test_SRC})

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main gem)
add_test(runUnitTests runUnitTests)
