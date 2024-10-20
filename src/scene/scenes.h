#pragma once

#include "scene.h"

namespace WhineEngine 
{
  class Scenes 
  {
    friend class Scene;
  public:
    static Scenes *Get() { return m_instance; }

    Scenes();

    void UpdateScenes();

    Scene *AddScene();
  private:
    static Scenes *m_instance;
    std::vector<std::unique_ptr<Scene>> m_scenes;
  };
}