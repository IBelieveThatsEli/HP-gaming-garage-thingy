#include "scene.h"

#include <glad/glad.h>
#include "camera.h"
#include "shader.h"

using namespace WhineEngine;

Scene *Scene::m_instance = nullptr;

Scene::Scene()
{
  m_instance = this;

  glEnable(GL_DEPTH_TEST); 
}

void Scene::addTriangle()
{
  m_cam = std::make_unique<Camera>(glm::vec3(4.0f, 4.0f, -5.0f));
  m_cam->SetCamMatrix(45.0f, 0.1f, 100.0f);
  m_cube = std::make_unique<Cube>();
  m_cube->CreateBuffers();

  m_cube->SetScale(glm::vec3(1.0f, 2.0f, 1.0f));
  m_cube->SetOrientation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Scene::Update()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (m_cube)
  {
    m_cube->UseBuffer();
    m_cube->UseShading();
    m_cam->UpdateMatrix(m_cube->GetShader(), "camProjection");
    m_cube->Update();
  }
}