add_library(texture STATIC texture.cpp)

target_include_directories(texture PUBLIC 
  texture.h
  libs/glad
  libs/stb
)

target_link_libraries(texture PUBLIC 
  glad
  stb
)