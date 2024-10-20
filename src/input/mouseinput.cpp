#include "mouseinput.h"

using namespace WhineEngine;

MouseInput *MouseInput::m_instance = nullptr;

MouseInput::MouseInput() :
  m_mousePos      {glm::vec2(0.0f)}, 
  m_lastMousePos  {glm::vec2(0.0f)},
  m_mouseOffset   {glm::vec2(0.0f)},
  m_maxMousePitch {glm::vec2(-89.0f, 89.0f)},
  m_firstMouse    { true }
{ m_instance = this; }

void MouseInput::SetupMousePos(Window &window)
{
  glfwSetCursorPosCallback(window.GetWindow(), MouseInput::mouse_callback);
}

void MouseInput::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (m_instance->m_firstMouse)
    {
      m_instance->m_lastMousePos = glm::vec2(xpos, ypos);
      m_instance->m_firstMouse = false;
    }

    float xoffset = xpos - m_instance->m_lastMousePos.x;
    float yoffset = m_instance->m_lastMousePos.y - ypos; 
    m_instance->m_lastMousePos = glm::vec2(xpos, ypos);

    xoffset *= m_instance->m_mouseSens;
    yoffset *= m_instance->m_mouseSens;

    m_instance->m_mousePos =  glm::vec2(m_instance->m_mousePos.x + xoffset,
                                        m_instance->m_mousePos.y + yoffset);

    // yaw   += xoffset;
    // pitch += yoffset;

    if(m_instance->m_mousePos.y > 89.0f)
    {
      m_instance->m_mousePos = glm::vec2(m_instance->GetMousePosition().x, 89.0f);
    }

    if(m_instance->m_mousePos.y < -89.0f) 
    {
      m_instance->m_mousePos = glm::vec2(m_instance->GetMousePosition().x, -89.0f);
    }    
}

void MouseInput::SetupScrollOffset(Window &window)
{
  glfwSetScrollCallback(window.GetWindow(), MouseInput::scroll_callback);
}

void MouseInput::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  m_instance->SetScrollOffset(glm::vec2((float)xoffset, (float)yoffset));
}