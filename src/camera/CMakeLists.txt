add_library(camera STATIC camera.cpp)

target_include_directories(camera PUBLIC 
  camera.h
  libs/glm
  ../shading
  ../win
)

target_link_libraries(camera PUBLIC
  glm
  shading
  win
)