/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

#include "../mesh/mesh.h"
#include "../camera/camera.h"

#include <memory>

namespace WhineEngine
{
  class Scene
  {
  public:
    static Scene *Get() { return m_instance; }
    Scene();

    Camera *AddCamera();

    Mesh *AddCube();

    Mesh *AddSphere();

    void Update();
    std::vector<std::unique_ptr<Mesh>> m_cubes;
  private:
    static Scene *m_instance;
    // std::unique_ptr<Mesh> m_mesh;
    std::unique_ptr<Camera> m_cam;
  };
}