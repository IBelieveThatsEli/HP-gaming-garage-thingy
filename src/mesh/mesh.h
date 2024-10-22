/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

#include <vector>
#include <memory>
#include "../shading/shader.h"
#include "../shading/texture.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>

namespace WhineEngine
{
  class Mesh
  {
  public:
    struct _Texture {
      unsigned int id;
      std::string type;
      std::string path;
    };

    std::vector<glm::vec3>    m_vertices;
    std::vector<glm::vec2>    m_UV;
    std::vector<unsigned int> m_indices;
    std::vector<glm::vec3>    m_normals;
    std::vector<_Texture>      m_textures;
  public:
    Mesh();
    Mesh(const std::vector<glm::vec3> &vertices);
    Mesh(const std::vector<glm::vec3> &vertices, const std::vector<std::uint32_t> &indices);
    
    ~Mesh();

    void CreateBuffers();

    void Update();

    void UseShading();
    void UseBuffer();
  
    void CreateShader(const char *vPath, const char *fPath);

    void CopyShader(std::unique_ptr<Shader> shader) { m_shader = std::move(shader); }

    Shader &GetShader() { return *m_shader; }

    void CreateTexture(const char *texPath);

    const glm::vec3 &GetPosition() const { return m_position; }
    
    void SetPosition(const glm::vec3 &position);
    
    const glm::vec3 &GetSale() { return m_scale; }
    
    void SetScale(const glm::vec3 &scale);

    void SetOrientation(float deg, const glm::vec3 &axis);
  private:
    std::unique_ptr<Shader>   m_shader  { nullptr };
    std::unique_ptr<Texture>  m_texture { nullptr };

    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;

    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::mat4 m_model;
  };
}