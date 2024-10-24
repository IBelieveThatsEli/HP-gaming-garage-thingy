/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "scene.h"

#include <glad/glad.h>
#include "../camera/camera.h"
#include "../shading/shader.h"
#include "../win/window.h"
#include "../mesh/cube.h"
#include "../mesh/sphere.h"

using namespace WhineEngine;

// ============================================================================== //

Scene *Scene::m_instance = nullptr;

// ============================================================================== //

Scene::Scene()
{
  m_instance = this;
  // TEMP
  glEnable(GL_DEPTH_TEST);
}

// ============================================================================== //

Camera *Scene::AddCamera()
{
  m_cam = std::make_unique<Camera>(glm::vec3(0.0f, 0.0f,  3.0f), 
                                   glm::vec3(0.0f, 0.0f, -1.0f), 
                                   glm::vec3(0.0f, 1.0f,  0.0f));
  m_cam->SetPerspective(45.0f, 0.1f, 100.0f);

  return m_cam.get();
}

// ============================================================================== //

Mesh *Scene::AddCube()
{
  m_cubes.emplace_back(std::make_unique<Cube>());
  return m_cubes.back().get();
}

// ============================================================================== //

Mesh *Scene::AddSphere()
{
  m_cubes.emplace_back(std::make_unique<Sphere>(1, 6, 8));
  return m_cubes.back().get();
}

// ============================================================================== //

void Scene::Update()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (m_cubes.size() == 0) return;  

  for (auto itr { m_cubes.begin() }; itr != m_cubes.end(); ++itr) 
  {
    (*itr)->Update();
    m_cam->Update((*itr)->GetShader());
  }
}

// ============================================================================== //