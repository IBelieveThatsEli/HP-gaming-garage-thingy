# add_subdirectory(engine)
# add_subdirectory(win)
# add_subdirectory(mesh)
# add_subdirectory(scene)
# add_subdirectory(shading)
# add_subdirectory(camera)
# add_subdirectory(input)

add_library(src STATIC
  camera/camera.cpp
  engine/engine.cpp
  input/input.cpp
  input/mouseinput.cpp
  mesh/cube.cpp
  mesh/mesh.cpp
  mesh/sphere.cpp
  scene/scene.cpp
  shading/shader.cpp
  shading/texture.cpp
  win/Window.cpp
)

target_include_directories(src PUBLIC
  camera/camera.h
  engine/app.h
  engine/engine.h
  input/input.h
  input/mouseinput.h
  mesh/cube.h
  mesh/mesh.h
  mesh/sphere.h
  scene/scene.h
  shading/shader.h
  shading/texture.h
  win/Window.h
  libs/glad
  libs/glm
  libs/stb
  libs/glfw
)

target_link_libraries(src PRIVATE
  glad
  glm
  stb
  glfw
)