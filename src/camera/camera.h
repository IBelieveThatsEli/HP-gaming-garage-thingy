/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

// WE GET THE ASPECT RATIO FROM THE WINDOW. THERE IS ONLY
// ONE  WINDOW, WE USE A STATIC VARIABLE TO KEEP TRACK OF 
// THE WINDOW INSTANCE, THATS HOW WE ARE ABLE TO USE  THE 
// WINDWOWS PUBLIC VARIABLES

namespace WhineEngine
{
  class Camera
  {
  public:
    static Camera *Get() { return m_instance; }
    
    Camera();
    Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up);

    void Update(Shader &shader);

    void SetPerspective(float fov, float near, float far);
    void SetOrthographic(float left, float right, float top, float bottom, float near, float far);

    void UpdateView();

    void SetPosition(const glm::vec3 &position);

    void SetCameraSpeed(const float camSpeed) { m_camSpeed = camSpeed; }

    float GetCamSpeed() { return m_camSpeed; }
  private:
    static Camera *m_instance;

    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_up;
    glm::vec3 m_right;

    float m_camSpeed = 0.05f;

    float m_fov;
    float m_near;
    float m_far;
    bool  m_perspective;

    glm::mat4 m_view;
    glm::mat4 m_projection;
  };
}