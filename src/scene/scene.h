/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

// #include "mesh.h"
#include "cube.h"
#include "camera.h"

#include <memory>

namespace WhineEngine
{
  class Scene
  {
  public:
    static Scene *Get() { return m_instance; }
    Scene();

    Camera *AddCamera();

    Cube *AddCube();

    void Update();
  private:
    static Scene *m_instance;
    // std::unique_ptr<Mesh> m_mesh;
    std::vector<std::unique_ptr<Cube>> m_cubes;
    std::unique_ptr<Camera> m_cam;
  };
}