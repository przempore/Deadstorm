cmake_minimum_required(VERSION 2.8.0)
project (gem)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 14)

file(GLOB gem_SRC
   gem/*.cpp
   gem/*.hpp
   gem/detail/*.hpp
   gem/detail/*.cpp
   gem/detail/*.inl
   gem/*.inl
   pugixml/*.cpp
   pugixml/*.hpp
   )

set(CMAKE_MODULE_PATH "../cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(BOOST REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

add_library(gem SHARED ${gem_SRC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/detail)
target_link_libraries(gem ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
