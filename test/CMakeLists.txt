cmake_minimum_required(VERSION 2.8.0)
project(unitTests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

file(GLOB test_SRC
        src/gem/*.cpp
        src/game/*.cpp)

# add_library(Deadstorm_obj OBJECT ${game_SRC})
add_executable(runUnitTests ${test_SRC} $<TARGET_OBJECTS:Deadstorm_obj>)

target_link_libraries(runUnitTests gtest gmock_main gem)
# add_test(runUnitTests runUnitTests)
add_test(NAME runUnitTests_test COMMAND runUnitTests)
