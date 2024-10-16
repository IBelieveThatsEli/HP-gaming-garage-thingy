add_library(shading STATIC 
  shader.cpp
  texture.cpp
)

target_include_directories(shading PUBLIC 
  shader.h
  texture.h
  libs/glad
  libs/stb
  libs/glm
)

target_link_libraries(shading PUBLIC
  glad
  glm
  stb
)