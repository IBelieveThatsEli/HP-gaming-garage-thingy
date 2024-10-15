#pragma once

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

namespace WhineEngine
{
  class Camera
  {
  public:
    static Camera *Get() { return m_instance; }
    
    Camera();
    Camera(const glm::vec3 &position);
    ~Camera();

    const glm::vec3 &GetPosition() { return m_position; }

    void SetPosition(const glm::vec3 &position) { m_position = position; }

    void SetCamMatrix(float FOVdeg, float nearPlane, float farPlane);

    void UpdateMatrix(Shader &shader, const char *uniform);

    // void Input(GLFWwindow *window);

  private:
    static Camera *m_instance;

    glm::vec3 m_position;
    glm::vec3 m_target;
    glm::vec3 m_direction;
    glm::vec3 m_up;
    glm::vec3 m_right;

    glm::mat4 m_cameraMatrix;
  };
}