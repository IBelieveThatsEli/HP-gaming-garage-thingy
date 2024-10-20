#include "scenes.h"

#include <glad/glad.h>

using namespace WhineEngine;

Scenes *Scenes::m_instance = nullptr;

Scenes::Scenes()
{
  m_instance = this; 
}

void Scenes::UpdateScenes()
{
  if (m_scenes.size() <= 0) return;

  // for (auto itr{m_scenes.begin()}; itr != m_scenes.end(); ++itr)
  // {
  //   (*itr)->Update();
  // }

  m_scenes.at(0)->Update();
}

Scene *Scenes::AddScene()
{
  m_scenes.emplace_back(std::make_unique<Scene>());
  return m_scenes.back().get();
}
