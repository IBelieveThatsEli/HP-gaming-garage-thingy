add_library(mesh STATIC
  mesh.cpp
  cube.cpp
  sphere.cpp
)

target_include_directories(mesh PUBLIC 
  mesh.h
  cube.h
  sphere.h
  libs/glad
  libs/glm
  ../shading
)

target_link_libraries(mesh PUBLIC 
  glad
  glm
  shading
)