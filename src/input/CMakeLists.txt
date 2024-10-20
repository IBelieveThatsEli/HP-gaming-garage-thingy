add_library(input STATIC 
  input.cpp
  mouseinput.cpp
)

target_include_directories(input PUBLIC 
  input.h
  mouseinput.h
  libs/glfw
  libs/glad
  libs/glm
  ../win
)

target_link_libraries(input PUBLIC
  glfw
  glad
  glm
)