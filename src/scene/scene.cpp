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
  // m_cam = std::make_unique<Camera>();
  // m_cam->updateMatrix(1.0f, 0.1f, 100.0f);
  // m_mesh = std::make_unique<Mesh>();
  m_cube = std::make_unique<Cube>();
  m_cube->CreateBuffers();
}

void Scene::Update()
{
  
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (m_cube)
  {
    // m_mesh->UpdateShading();
    // m_cube->UpdateShading();
    // m_cam->Matrix(m_cube->GetShader(), "camProjection");
    // m_mesh->Update();
    m_cube->Update();
  }
}