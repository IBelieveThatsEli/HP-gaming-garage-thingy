#include "mesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

//TODO remove this
#include <iostream>

using namespace WhineEngine;

Mesh::Mesh()
{
  // float vertices[] = {
  //   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
  //    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
  //    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  //    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  //   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
  //   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

  //   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  //    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
  //    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
  //    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
  //   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
  //   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

  //   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  //   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  //   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  //   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  //   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  //   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

  //    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  //    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  //    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  //    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  //    0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  //    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

  //   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  //    0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
  //    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
  //    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
  //   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  //   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

  //   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
  //    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  //    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  //    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  //   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
  //   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
  // };

  // glGenVertexArrays(1, &m_VAO);

  // glGenBuffers(1, &m_VBO);
  // // glGenBuffers(1, &m_EBO);
  
  // glBindVertexArray(m_VAO);

  // glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  // // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);  

  // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  // glEnableVertexAttribArray(1);

  // shader = std::make_unique<Shader>("../res/shaders/default.vs", "../res/shaders/default.fs");

  // glm::mat4 model = glm::mat4(1.0f);
  // model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

  // shader->Use();
  // shader->SetMatrix("model", model);

  // texture = std::make_unique<Texture>("../res/textures/container.jpg");
}

Mesh::Mesh(const std::vector<glm::vec3> &vertices) :
  m_vertices{vertices}
{}
    
Mesh::Mesh(const std::vector<glm::vec3> &vertices, const std::vector<std::uint32_t> &indices) :
  m_vertices{vertices},
  m_indices{indices}
{}

Mesh::~Mesh()
{
  texture = nullptr;
  shader = nullptr;
  glDeleteVertexArrays(1, &m_VAO);
  glDeleteBuffers(1, &m_VBO);
  // glDeleteBuffers(1, &m_EBO);
}

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
  // glBufferData(GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);

  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)0);
  glEnableVertexAttribArray(0);  

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  shader = std::make_unique<Shader>("../res/shaders/default.vs", "../res/shaders/default.fs");

  glm::mat4 model = glm::mat4(1.0f);
  model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

  glm::mat4 view = glm::mat4(1.0f);
  view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));

  glm::mat4 projection = glm::mat4(1.0f);
  projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);

  shader->Use();
  shader->SetMatrix("model", model);
  shader->SetMatrix("view", view);
  shader->SetMatrix("projection", projection);

  texture = std::make_unique<Texture>("../res/textures/container.jpg");
}

void Mesh::UpdateShading()
{
  texture->Use();
  shader->Use();
  glBindVertexArray(m_VAO);
}

void Mesh::Update()
{
  texture->Use();
  shader->Use();
  glBindVertexArray(m_VAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Mesh::SetOrientation(float deg, const glm::vec3 &axis) 
{
  m_model = glm::rotate(m_model, glm::radians(deg), axis);
}