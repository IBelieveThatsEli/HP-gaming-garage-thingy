add_library(mesh STATIC
  mesh.cpp
)

target_include_directories(mesh PUBLIC 
  mesh.h
  libs/glad
  ../shading
)

target_link_libraries(mesh PUBLIC 
  glad
  shading
)