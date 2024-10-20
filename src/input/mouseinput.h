#pragma once

#include <glm/vec2.hpp>
#include "Window.h"

namespace WhineEngine
{
  class MouseInput
  {
  public:
    static MouseInput *Get() { return m_instance; }

    MouseInput();

    static void SetupMousePos(Window &window);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

    const float &GetMouseSense() { return m_mouseSens; }
    void SetMouseSens(const float &sens) { m_mouseSens = sens; }

    const glm::vec2 &GetMousePosition() { return m_mousePos; }
    void SetMousePosition(const glm::vec2 &position) { m_mousePos = position; }

    const glm::vec2 &GetLastMousePos() { return m_lastMousePos; }
    void SetLastMousePos(const glm::vec2 &lastPos) { m_lastMousePos = lastPos; }

    const glm::vec2 &GetMouseOffset() { return m_mouseOffset; }
    void SetMouseOffset(const glm::vec2 &mouseOffset) { m_mouseOffset = mouseOffset; }

    const glm::vec2 &GetMaxMousePitch() { return m_maxMousePitch; }
    void SetMaxMousePitch(const glm::vec2 &maxPitch) { m_maxMousePitch = maxPitch; }

    static void SetupScrollOffset(Window &window);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    const glm::vec2 &GetScrollOffset() { return m_scrollOffset; }
    void SetScrollOffset(const glm::vec2 &scrollOffset) { m_scrollOffset = scrollOffset; }

  private:
    static MouseInput *m_instance;

    glm::vec2 m_mousePos      { glm::vec2(0.0f) };
    glm::vec2 m_lastMousePos  { glm::vec2(0.0f) };
    glm::vec2 m_mouseOffset   { glm::vec2(0.0f) };
    glm::vec2 m_maxMousePitch { glm::vec2(0.0f) };

    glm::vec2 m_scrollOffset  { glm::vec2(0.0f) };

    float m_mouseSens         { 0.2f };
    float m_scrollSens        { 0.2f };
    float m_firstMouse        { true };
  };
}