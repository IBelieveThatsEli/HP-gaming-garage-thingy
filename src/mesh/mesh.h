#pragma once

#include <vector>
#include <memory>
#include "shader.h"
#include "texture.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>

// hello inexperienced programmer here *wave emoji*
// DO NOT INCLUDE THIS MESH CLASS AS IS, AS MAIN CLASS UNLEESS, that is if it is implemented // WHICH IT IS NOT
// UNLESS U INTEND TO USE IT FOR LOADING MODELS.
// so for example use the cube class instead. u catch my drift?

namespace WhineEngine
{
  class Mesh
  {
  public:
    std::vector<glm::vec3> m_vertices;
    std::vector<glm::vec2> m_UV;
    std::vector<std::uint32_t> m_indices;
  public:
    Mesh();
    Mesh(const std::vector<glm::vec3> &vertices);
    Mesh(const std::vector<glm::vec3> &vertices, const std::vector<std::uint32_t> &indices);
    
    ~Mesh();

    void CreateBuffers();

    void UpdateShading();

    void Update();

    Shader &GetShader() { return *shader; }

    const glm::vec3 &GetPosition() const { return m_position; }
    
    void SetPosition(const glm::vec3 &position) { m_position = position; }
    
    const glm::vec3 &GetSize() { return m_size; }
    
    void SetSize(const glm::vec3 &size) {  m_size = size; }

    void SetOrientation(float deg, const glm::vec3 &axis);
  private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;

    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;

    glm::vec3 m_position;
    glm::vec3 m_size;
    glm::mat4 m_model;
  };
}