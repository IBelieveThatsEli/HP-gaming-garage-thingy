add_executable(game main.cpp)

target_include_directories(game PRIVATE
  main.h
  libs/glfw
  libs/glad
  libs/glm
  libs/stb
  src
)
  # ../src/win
  # ../src/engine
  # ../src/mesh
  # ../src/scene
  # ../src/shading
  # ../src/camera
  # ../src/input

target_link_libraries(game PRIVATE
  glfw
  glad
  glm
  stb
  src
)
  # win
  # engine
  # mesh
  # scene
  # shading
  # camera
  # input