add_library(win STATIC Window.cpp)

target_include_directories(win PUBLIC 
  Window.h 
  libs/glfw
  libs/glad
)

target_link_libraries(win PUBLIC 
  glfw
  glad
)