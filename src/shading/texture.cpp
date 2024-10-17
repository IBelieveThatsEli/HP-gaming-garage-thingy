/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "texture.h"

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

using namespace WhineEngine;

// ============================================================================== //

Texture::Texture(const std::string_view filePath)
{
  glGenTextures(1, &m_id);
  glBindTexture(GL_TEXTURE_2D, m_id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  stbi_set_flip_vertically_on_load(true);  

  int width, height, nrChannels;
  unsigned char *data = stbi_load(filePath.data(), &width, &height, &nrChannels, 0);
  if (data)
  {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } 
  else 
  {
    std::cout << "FAILED TO LOAD TEXTURE\n";
    exit(EXIT_FAILURE);
  }
  stbi_image_free(data);
}

// ============================================================================== //

Texture::~Texture()
{

}

// ============================================================================== //

void Texture::Use()
{
  glBindTexture(GL_TEXTURE_2D, m_id);
}

// ============================================================================== //