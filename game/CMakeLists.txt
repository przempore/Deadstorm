file(GLOB game_SRC src/*.cpp
	include/*.hpp)

include_directories("include")

add_executable(Deadstorm ${game_SRC})

target_link_libraries(Deadstorm gem)
