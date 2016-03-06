cmake_minimum_required(VERSION 2.8.0)
project(unitTests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB test_SRC
        src/gem/*.cpp
        src/game/*.cpp)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ../lib ../game)
add_executable(runUnitTests ${test_SRC} $<TARGET_OBJECTS:Deadstorm_obj>)

target_link_libraries(runUnitTests gtest gtest_main gem)
add_test(runUnitTests runUnitTests)
