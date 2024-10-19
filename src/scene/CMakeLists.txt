add_library(scene STATIC
  scene.cpp
)

target_include_directories(scene PUBLIC
  scene.h
  ../mesh
  libs/glad
  libs/glm
  ../camera
  ../win
)

target_link_libraries(scene PRIVATE
  mesh
  glad
  glm
  camera
  win
)