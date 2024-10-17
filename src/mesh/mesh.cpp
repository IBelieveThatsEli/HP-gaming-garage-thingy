/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "mesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

//TODO remove this
#include <iostream>

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
  // glDeleteBuffers(1, &m_EBO);
}

// ============================================================================== //

void Mesh::CreateBuffers()
{
  std::vector<float> data;

  data.reserve(m_vertices.size() * 3 + m_UV.size() * 2);
  std::cout << "VERTICES SIZE: " << m_vertices.size() << '\n';
  for (int i = 0; i < m_vertices.size(); ++i) {
    data.push_back(m_vertices[i].x);
    data.push_back(m_vertices[i].y);
    data.push_back(m_vertices[i].z);
    data.push_back(m_UV[i].x);
    data.push_back(m_UV[i].y);
  }

  glGenVertexArrays(1, &m_VAO);

  glGenBuffers(1, &m_VBO);
  // glGenBuffers(1, &m_EBO);  
  glBindVertexArray(m_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  std::cout << data.size();
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
  // TODO test if ebo has values...
  // glBufferData(GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);

  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)0);
  glEnableVertexAttribArray(0);  

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // TODO: default shader btw
  m_shader = std::make_unique<Shader>("../res/shaders/default.vs", "../res/shaders/default.fs");

  m_model = glm::mat4(1.0f);
  // model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

  m_shader->Use();
  m_shader->SetMatrix("model", m_model);

  m_texture = std::make_unique<Texture>("../res/textures/container.jpg");
}

// ============================================================================== //

void Mesh::UseShading()
{
  m_texture->Use();
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
  glDrawArrays(GL_TRIANGLES, 0, 36);
}

// ============================================================================== //

// set rotation? is this a good name...
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