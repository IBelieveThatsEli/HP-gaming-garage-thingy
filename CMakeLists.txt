cmake_minimum_required(VERSION 3.10.0)
project(project VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)
add_subdirectory(libs/glm)
add_subdirectory(libs/stb)

add_subdirectory(src)

add_subdirectory(game)