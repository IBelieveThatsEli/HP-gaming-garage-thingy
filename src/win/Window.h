/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <stdint.h>
#include <string>
#include <string_view>

#include <set>

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

    GLFWwindow *GetWindow() { return m_window; }

  private:
    // friend void framebuffer_callback(GLFWwindow *window, int width, int height);
    // friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static Window *m_instance;

    std::uint32_t m_width, m_height;
    std::string m_title;
    GLFWwindow *m_window{nullptr};


    void createWindow();
  };
}