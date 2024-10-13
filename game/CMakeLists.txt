add_executable(game main.cpp)

target_include_directories(game PRIVATE
  main.h
  libs/glfw
  libs/glad
  libs/glm
  ../src/win
  ../src/engine
  ../src/mesh
  ../src/scene
  ../src/shading
)
  # src/engine

target_link_libraries(game PRIVATE
  glfw
  glad
  glm
  win
  engine
  mesh
  scene
  shading
)
  # PRIVATE engine