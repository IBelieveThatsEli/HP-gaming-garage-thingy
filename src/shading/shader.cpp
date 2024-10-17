/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#include "shader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

using namespace WhineEngine;

// ============================================================================== //

namespace Read
{
  std::string FileContents(const std::string_view filePath)
  {
    std::ifstream in(filePath.data(), std::ios::in | std::ios::binary);
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

// ============================================================================== //

Shader::Shader()
{
  Load("../res/shaders/vert.glsl", "../res/shaders/vert.glsl");
}

// ============================================================================== //

Shader::Shader(const std::string_view vsPath, const std::string_view fsPath)
{
  Load(vsPath, fsPath);
}

// ============================================================================== //

Shader::~Shader()
{
  glDeleteShader(m_id);
}

// ============================================================================== //

void Shader::Load(const std::string_view vsPath, const std::string_view fsPath)
{
  std::string vsCode = Read::FileContents(vsPath);
  std::string fsCode = Read::FileContents(fsPath);

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

// ============================================================================== //

void Shader::Use()
{
  glUseProgram(m_id);
}

// ============================================================================== //

// improve name...
void Shader::SetShaderLocation(const std::string_view vsPath, const std::string_view fsPath)
{
  Load(vsPath, fsPath);
}

// ============================================================================== //

void Shader::SetInt(std::string_view location, int value)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform1i(m_id, value);
}

// ============================================================================== //

void Shader::SetBool(std::string_view location, bool value)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform1i(loc, value);
}

// ============================================================================== //

void Shader::SetFloat(std::string_view location, float value)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform1f(loc, value);
}

// ============================================================================== //

void Shader::SetMatrix(std::string_view location, glm::mat4 value) 
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

// ============================================================================== //

void Shader::SetVector(std::string_view location, const glm::vec2 &value)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform2fv(loc, 1, &value[0]);
}

void Shader::SetVector(std::string_view location, float x, float y)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform2f(loc, x, y);
}

// ============================================================================== //

void Shader::SetVector(std::string_view location, const glm::vec3 &value)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform3fv(loc, 1, &value[0]);
}

void Shader::SetVector(std::string_view location, float x, float y, float z)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform3f(loc, x, y, z);
}

// ============================================================================== //

void Shader::SetVector(std::string_view location, const glm::vec4 &value)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform4fv(loc, 1, &value[0]);
}

void Shader::SetVector(std::string_view location, float x, float y, float z, float k)
{
  int loc = glGetUniformLocation(m_id, location.data());
  glUniform4f(loc, x, y, z, k);
}

// ============================================================================== //