/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

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
    std::vector<glm::vec3> m_normals;
  public:
    Mesh();
    // THE LAYOUT OF THE MESH CONSTRUCTOR WILL ULTIMATELY BE DECIDED BY THE
    // WAY OBJ OR FBX FILES ARE SAVED
    Mesh(const std::vector<glm::vec3> &vertices);
    Mesh(const std::vector<glm::vec3> &vertices, const std::vector<std::uint32_t> &indices);
    
    ~Mesh();

    void CreateBuffers();

    void Update();

    void UseShading();
    void UseBuffer();
  
    void CreateShader(const char *vPath, const char *fPath);

    Shader &GetShader() { return *m_shader; }

    void CreateTexture(const char *texPath, const char *specularMap);

    const glm::vec3 &GetPosition() const { return m_position; }
    
    void SetPosition(const glm::vec3 &position);
    
    const glm::vec3 &GetSale() { return m_scale; }
    
    void SetScale(const glm::vec3 &scale);

    void SetOrientation(float deg, const glm::vec3 &axis);
  private:
    std::unique_ptr<Shader>   m_shader;
    std::unique_ptr<Texture>  m_texture { nullptr };

    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;

    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::mat4 m_model;
  };
}