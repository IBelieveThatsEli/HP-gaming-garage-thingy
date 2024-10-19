/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "Window.h"

#include <iostream>

using namespace WhineEngine;

// ============================================================================== //

static void framebuffer_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

// ============================================================================== //

Window *Window::m_instance = nullptr;

// ============================================================================== //

Window::Window(std::uint32_t width, std::uint32_t height, std::string_view title) :
  m_width{width}, m_height{height}, m_title{title}
{
  m_instance = this;

  createWindow();

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    exit(EXIT_FAILURE);
  }   

  glfwSetFramebufferSizeCallback(m_window, framebuffer_callback);
}

// ============================================================================== //

Window::~Window()
{
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

// ============================================================================== //

void Window::Update()
{
  glfwPollEvents();
  glfwSwapBuffers(m_window);
}

// ============================================================================== //

void Window::createWindow()
{
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
  
  glfwMakeContextCurrent(m_window); 
}

// ============================================================================== //