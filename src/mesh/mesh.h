#pragma once

namespace WhineEngine
{
  class Mesh
  {
  public:
    unsigned int m_VAO;
    unsigned int m_VBO;
    // unsigned int m_EBO;
    unsigned int shaderProgram;

    Mesh();
    ~Mesh();

    void Update();
  private:
  };
}