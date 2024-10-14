#include "mesh.h"

#include <glad/glad.h>

using namespace WhineEngine;

Mesh::Mesh()
{
  float vertices[] = {
     0.5f,  0.5f, 0.0f,  1.0f, 1.0f,// top right
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f,// bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,// bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,// top left 
  };

  unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
  };

  glGenVertexArrays(1, &m_VAO);

  glGenBuffers(1, &m_VBO);
  glGenBuffers(1, &m_EBO);
  
  glBindVertexArray(m_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);  

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  shader = std::make_unique<Shader>("../res/shaders/default.vs", "../res/shaders/default.fs");
  texture = std::make_unique<Texture>("../res/textures/container.jpg");
}

Mesh::~Mesh()
{
  texture = nullptr;
  shader = nullptr;
  glDeleteVertexArrays(1, &m_VAO);
  glDeleteBuffers(1, &m_VBO);
  glDeleteBuffers(1, &m_EBO);
}

void Mesh::Update()
{
  texture->Use();
  shader->Use();
  glBindVertexArray(m_VAO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  // glDrawArrays(GL_TRIANGLES, 0, 3);
}