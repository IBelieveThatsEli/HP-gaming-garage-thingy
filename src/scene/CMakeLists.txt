add_library(scene STATIC
  scene.cpp
)

target_include_directories(scene PUBLIC
  scene.h
  ../mesh
  libs/glad
)

target_link_libraries(scene PRIVATE
  mesh
  glad
)