project (gem)

file(GLOB gem_SRC
   gem/*.cpp
   gem/*.hpp
   gem/detail/*.hpp
   gem/detail/*.cpp
   gem/detail/*.inl
   gem/*.h
   gem/*.inl
   pugixml/*.cpp
   pugixml/*.hpp
   )

add_library(gem STATIC ${gem_SRC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/detail)
target_link_libraries(gem ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})