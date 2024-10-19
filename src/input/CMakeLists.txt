add_library(input STATIC 
  input.cpp
)

target_include_directories(input PUBLIC 
  input.h
  ../win
  libs/glfw
)

target_link_libraries(input PUBLIC
  glfw
)