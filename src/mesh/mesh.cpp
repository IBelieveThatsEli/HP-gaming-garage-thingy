/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "mesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace WhineEngine;

// ============================================================================== //

Mesh::Mesh()
{}

// ============================================================================== //

Mesh::Mesh(const std::vector<glm::vec3> &vertices) :
  m_vertices{vertices}
{}

// ============================================================================== //    

Mesh::Mesh(const std::vector<glm::vec3> &vertices, const std::vector<std::uint32_t> &indices) :
  m_vertices{vertices},
  m_indices{indices}
{}

// ============================================================================== //

Mesh::~Mesh()
{
  m_texture = nullptr;
  m_shader = nullptr;

  glDeleteVertexArrays(1, &m_VAO);
  glDeleteBuffers(1, &m_VBO);

  if (m_indices.size() > 0)
  {
    glDeleteBuffers(1, &m_EBO);
  }
}

// ============================================================================== //

void Mesh::CreateBuffers()
{
  std::vector<float> data;
  if (m_UV.size() > 0)
  {
    if (m_normals.size() > 0)
    {
      data.reserve(m_vertices.size() * 3 + m_UV.size() * 2 + m_normals.size() * 3);
    }
    else
    {
      data.reserve(m_vertices.size() * 3 + m_UV.size() * 2);
    }
  }
  
  for (int i = 0; i < m_vertices.size(); ++i) 
  {
    data.push_back(m_vertices[i].x);
    data.push_back(m_vertices[i].y);
    data.push_back(m_vertices[i].z);
    
    if (m_UV.size() > 0)
    {
      data.push_back(m_UV[i].x);
      data.push_back(m_UV[i].y);
    }

    if (m_normals.size() > 0)
    {
      data.push_back(m_normals[i].x);
      data.push_back(m_normals[i].y);
      data.push_back(m_normals[i].z);
    }
  }

  glGenVertexArrays(1, &m_VAO);

  glGenBuffers(1, &m_VBO);
  
  if (m_indices.size() > 0) 
    glGenBuffers(1, &m_EBO);  

  glBindVertexArray(m_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
  
  if (m_indices.size() > 0)
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);
  }

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
  glEnableVertexAttribArray(0);  

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(5 * sizeof(float)));
  glEnableVertexAttribArray(2);
}

// ============================================================================== //

void Mesh::CreateShader(const char *vPath, const char *fPath)
{
  m_shader = std::make_unique<Shader>(vPath, fPath);
  
  m_model = glm::mat4(1.0f);
  m_shader->Use();
  m_shader->SetMatrix("model", m_model);
}

// ============================================================================== //

void Mesh::CreateTexture(const char *texPath)
{
  m_texture = std::make_unique<Texture>(texPath);
}

// ============================================================================== //

void Mesh::UseShading()
{
  if (m_texture != nullptr) m_texture->Use();

  m_shader->Use();
}

// ============================================================================== //

void Mesh::UseBuffer()
{
  glBindVertexArray(m_VAO);
}

// ============================================================================== //

void Mesh::Update()
{
  UseShading();

  UseBuffer();
  
  if (m_indices.size() > 0) 
  {
    glDrawElements(GL_TRIANGLES, (GLsizei)m_indices.size(), GL_UNSIGNED_INT, 0);
  }
  else 
  {
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)m_vertices.size());
  }
}

// ============================================================================== //

void Mesh::SetOrientation(float deg, const glm::vec3 &axis) 
{
  m_model = glm::rotate(m_model, glm::radians(deg), axis);
  m_shader->SetMatrix("model", m_model);
}

// ============================================================================== //

void Mesh::SetPosition(const glm::vec3 &position)
{
  m_position = position;
  m_model = glm::translate(m_model, position);
  m_shader->SetMatrix("model", m_model);
}

// ============================================================================== //

void Mesh::SetScale(const glm::vec3 &scale)
{
  m_scale = scale;
  m_model = glm::scale(m_model, scale);
  m_shader->SetMatrix("model", m_model);

}
// ============================================================================== //