#pragma once

#include "mesh.h"
#include "camera.h"

#include <memory>

namespace WhineEngine
{
  class Scene
  {
  public:
    static Scene *Get() { return m_instance; }

    Scene();
    
    void Update();

    void addTriangle();
  private:
    static Scene *m_instance;
    std::unique_ptr<Mesh> m_mesh;
    std::unique_ptr<Camera> m_cam;
  };
}