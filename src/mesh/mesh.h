#pragma once

#include <vector>
#include <memory>
#include "shader.h"
#include "texture.h"

// #include <glm/vec3.hpp>

namespace WhineEngine
{
  class Mesh
  {
  public:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    // unsigned int shaderProgram;

    Mesh();
    // Mesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices);
    ~Mesh();

    void Update();
  private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;
  };
}