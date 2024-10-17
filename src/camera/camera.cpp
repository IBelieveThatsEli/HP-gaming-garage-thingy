/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "camera.h"

#include "Window.h"

using namespace WhineEngine;

// ============================================================================== //

Camera *Camera::m_instance = nullptr;

// ============================================================================== //

Camera::Camera()
{
  m_instance = this;
}

// ============================================================================== //

Camera::Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up) :
  m_position{position}, m_forward{forward}, m_up{up}
{
  m_instance = this;
  UpdateView();
}

// ============================================================================== //

void Camera::Update(Shader &shader)
{
  UpdateView();
  shader.SetMatrix("view", m_view);
  shader.SetMatrix("projection", m_projection);
}

// ============================================================================== //

void Camera::SetPerspective(float fov, float near, float far)
{
  m_perspective = true;
  m_projection = glm::perspective(fov, Window::Get()->AspectRatio(), near, far);
  m_fov = fov;
  m_near = near;
  m_far = far;
}

// ============================================================================== //

void Camera::SetOrthographic(float left, float right, float top, float bottom, float near, float far)
{
  m_perspective = false;
  // m_projection = glm::orthographic(left)
  //TODO MABE: make 2d
}

// ============================================================================== //

void Camera::UpdateView()
{
  m_view = glm::lookAt(m_position, m_position + m_forward, m_up);
}

// ============================================================================== //

void Camera::SetPosition(const glm::vec3 &position)
{
  m_position = position;
}

// ============================================================================== //