add_executable(game main.cpp)

target_include_directories(game PRIVATE
  main.h
  libs/glfw
  libs/glad
  ../src/win
  ../src/engine
  ../src/mesh
  ../src/scene
)
  # src/engine

target_link_libraries(game PRIVATE
  glfw
  glad
  win
  engine
  mesh
  scene
)
  # PRIVATE engine