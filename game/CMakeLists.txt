file(GLOB game_SRC src/*.cpp
        include/*.hpp
        include/*.inl
        include/tools/*.hpp)

set(CMAKE_CXX_STANDARD 14)
set(REPO ../)

include_directories("include")
include_directories("assets")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -pedantic -Wall")
set(CMAKE_MODULE_PATH "../cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(BOOST REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

file(COPY ${Deadstorm_SOURCE_DIR}/game/assets DESTINATION ${Deadstorm_BINARY_DIR}/game)

add_library(Deadstorm_obj ${game_SRC})
add_executable(Deadstorm src/main/main.cpp)

target_link_libraries(Deadstorm gem Deadstorm_obj)
