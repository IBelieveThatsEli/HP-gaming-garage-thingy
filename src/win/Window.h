#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <stdint.h>
#include <string>
#include <string_view>

namespace WhineEngine
{
  class Window
  {
  public:
    static Window *Get() { return m_instance; }

    Window(std::uint32_t width, std::uint32_t height, std::string_view title);
    ~Window();

    void Update();

    const std::string_view GetTitle() const { return m_title; }

    void SetTitle(std::string_view title) { m_title = title; }

    bool IsWindowOpen() const { return !glfwWindowShouldClose(m_window); }

    float AspectRatio() { return static_cast<float>(m_width) / m_height; }
  private:
    static Window *m_instance;

    std::uint32_t m_width, m_height;
    std::string m_title;
    GLFWwindow *m_window{nullptr};

    void createWindow();
  };
}