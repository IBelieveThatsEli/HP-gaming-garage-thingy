# Install script for directory: C:/Users/elipe/OneDrive/Desktop/Project/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/project")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/engine/cmake_install.cmake")
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/win/cmake_install.cmake")
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/mesh/cmake_install.cmake")
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/scene/cmake_install.cmake")
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/shading/cmake_install.cmake")
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/camera/cmake_install.cmake")
  include("C:/Users/elipe/OneDrive/Desktop/Project/bin/src/input/cmake_install.cmake")

endif()

