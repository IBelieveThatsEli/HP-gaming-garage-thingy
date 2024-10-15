#pragma once

#include <string>

#include <glm/mat4x4.hpp>

namespace WhineEngine
{
  class Shader
  {
  public:
    Shader();
    Shader(const std::string &vsPath, const std::string &fsPath);
    ~Shader();

    void Load(const std::string &vsPath, const std::string &fsPath);

    void Use();

    //void SetInt         (std::string location, int   value);
    //void SetBool        (std::string location, bool  value);
    //void SetFloat       (std::string location, float value);
    //void SetVector      (std::string location, math::vec2  value);
    //void SetVector      (std::string location, math::vec3  value);
    //void SetVector      (std::string location, math::vec4  value);
    //void SetVectorArray (std::string location, int size, const std::vector<math::vec2>& values);
    //void SetVectorArray (std::string location, int size, const std::vector<math::vec3>& values);
    //void SetVectorArray (std::string location, int size, const std::vector<math::vec4>& values);
    //void SetMatrix      (std::string location, math::mat2 value);
    //void SetMatrix      (std::string location, math::mat3 value);
    void SetMatrix      (std::string location, glm::mat4 value);
    //void SetMatrixArray (std::string location, int size, math::mat2* values);
    //void SetMatrixArray (std::string location, int size, math::mat3* values);
    //void SetMatrixArray (std::string location, int size, math::mat4* values);
  private:
    unsigned int m_id;
  };
}