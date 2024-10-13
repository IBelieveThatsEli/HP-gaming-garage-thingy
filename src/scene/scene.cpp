#include "scene.h"

#include <glad/glad.h>

using namespace WhineEngine;

Scene *Scene::m_instance = nullptr;

Scene::Scene()
{
  m_instance = this;
}

void Scene::addTriangle()
{
  m_mesh = std::make_unique<Mesh>();
}

void Scene::Update()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  if (m_mesh)
  {
    m_mesh->Update();
  }
}