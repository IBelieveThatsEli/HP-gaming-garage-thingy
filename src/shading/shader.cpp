#include "shader.h"

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace WhineEngine;

namespace Read
{
  std::string FileContents(const std::string &filePath)
  {
    std::ifstream in(filePath.c_str(), std::ios::in | std::ios::binary);
    if (!in)
    {
      std::cout << "FAILED TO OPEN FILE\n";
      exit(EXIT_FAILURE);
    }
    std::stringstream ss;
    ss << in.rdbuf();
    in.close();
    return(ss.str());
  }
}

Shader::Shader()
{
  Load("../res/shaders/vert.glsl", "../res/shaders/vert.glsl");
}

Shader::Shader(const std::string &vsPath, const std::string &fsPath)
{
  Load(vsPath, fsPath);
}

Shader::~Shader()
{
  glDeleteShader(m_id);
}

void Shader::Load(const std::string &vsPath, const std::string &fsPath)
{
  std::string vsCode = Read::FileContents(vsPath.c_str());
  std::string fsCode = Read::FileContents(fsPath.c_str());

  const char *vertCode = vsCode.c_str();
  const char *fragCode = fsCode.c_str();

  int success;
  char infoLog[512];

  unsigned int vShader, fShader;
  vShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vShader, 1, &vertCode, nullptr);
  glCompileShader(vShader);

  glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(vShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  };

  fShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fShader, 1, &fragCode, nullptr);
  glCompileShader(fShader);

  glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(fShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  };

  m_id = glCreateProgram();
  glAttachShader(m_id, vShader);
  glAttachShader(m_id, fShader);
  glLinkProgram(m_id);

  glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(m_id, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::SHADERPROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
  };

  glDeleteShader(vShader);
  glDeleteShader(fShader); 

}

void Shader::Use()
{
  glUseProgram(m_id);
}