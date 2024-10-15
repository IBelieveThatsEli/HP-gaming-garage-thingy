#include "camera.h"

#include "Window.h"

using namespace WhineEngine;

Camera *Camera::m_instance = nullptr;

Camera::Camera()
{
  m_instance = this;

  m_position  = { glm::vec3(0.0f, 0.0f, -3.0f) };
  m_target    = { glm::vec3(0.0f, 0.0f, 0.0f) };
  m_direction = {  glm::normalize(m_position - m_target) };
  m_up        = { glm::vec3(0.0f, 1.0f, 0.0f) };
  m_right     = { glm::normalize(glm::cross(m_up, m_direction)) };
}

Camera::Camera(const glm::vec3 &position) :
  m_position  { position },
  m_target    { glm::vec3(0.0f, 0.0f, 0.0f) },
  m_direction { glm::normalize(m_position - m_target) },
  m_up        { glm::vec3(0.0f, 1.0f, 0.0f) },
  m_right     { glm::normalize(glm::cross(m_up, m_direction)) }
{
  m_instance = this;
}

Camera::~Camera()
{

}

void Camera::SetCamMatrix(float FOVdeg, float nearPlane, float farPlane)
{
  glm::mat4 view = glm::mat4(1.0f);
  glm::mat4 projection = glm::mat4(1.0f);

  view = glm::lookAt(m_position, m_target, m_up);

  projection = glm::perspective(glm::radians(FOVdeg), Window::Get()->AspectRatio(), nearPlane, farPlane);

  m_cameraMatrix = projection * view;
}

void Camera::UpdateMatrix(Shader &shader, const char *uniform)
{
  shader.SetMatrix(uniform, m_cameraMatrix);
}
