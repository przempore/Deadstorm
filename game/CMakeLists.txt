file(GLOB game_SRC src/*.cpp
	include/*.hpp)

include_directories("include")

add_library(Deadstorm_obj OBJECT ${game_SRC})
add_executable(Deadstorm $<TARGET_OBJECTS:Deadstorm_obj> src/main/main.cpp)

target_link_libraries(Deadstorm gem)
