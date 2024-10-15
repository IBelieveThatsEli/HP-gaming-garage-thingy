#include "scene.h"

#include <glad/glad.h>
#include "camera.h"
#include "shader.h"

using namespace WhineEngine;

Scene *Scene::m_instance = nullptr;

Scene::Scene()
{
  m_instance = this;
}

void Scene::addTriangle()
{
  m_cam = std::make_unique<Camera>();
  m_cam->updateMatrix(1.0f, 0.1f, 100.0f);
  m_mesh = std::make_unique<Mesh>();
}

void Scene::Update()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (m_mesh)
  {
    m_mesh->UpdateShading();
    m_cam->Matrix(m_mesh->GetShader(), "camProjection");
    m_mesh->Update();
  }
}