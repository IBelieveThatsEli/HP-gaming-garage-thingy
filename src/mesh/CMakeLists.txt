add_library(mesh STATIC
  mesh.cpp
  cube.cpp
)

target_include_directories(mesh PUBLIC 
  mesh.h
  cube.h
  libs/glad
  libs/glm
  ../shading
)

target_link_libraries(mesh PUBLIC 
  glad
  glm
  shading
)