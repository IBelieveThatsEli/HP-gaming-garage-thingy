add_library(input STATIC 
  input.cpp
)

target_include_directories(input PUBLIC 
  input.h
  libs/glfw
  libs/glad
  ../win
)

target_link_libraries(input PUBLIC
  glfw
  glad
)