add_library(shading STATIC shader.cpp)

target_include_directories(shading PUBLIC 
  shader.h
  libs/glad
)

target_link_libraries(shading PUBLIC
  glad
)