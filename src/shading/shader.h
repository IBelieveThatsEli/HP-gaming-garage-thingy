/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

#include <string_view>

#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace WhineEngine
{
  class Shader
  {
  public:
    Shader();
    Shader(const std::string_view vsPath, const std::string_view fsPath);
    ~Shader();

    void SetShaderLocation(const std::string_view vsPath, const std::string_view fsPath);

    void Load(const std::string_view vsPath, const std::string_view fsPath);

    void Use();

    //void SetInt         (std::string location, int   value);
    //void SetBool        (std::string location, bool  value);
    //void SetFloat       (std::string location, float value);
    void SetVector      (std::string_view location, const glm::vec2 &value);
    void SetVector      (std::string_view location, float x, float y);
    void SetVector      (std::string_view location, const glm::vec3 &value);
    void SetVector      (std::string_view location, float x, float y, float z);
    void SetVector      (std::string_view location, const glm::vec4 &value);
    void SetVector      (std::string_view location, float x, float y, float z, float k);
    //void SetVectorArray (std::string location, int size, const std::vector<math::vec2>& values);
    //void SetVectorArray (std::string location, int size, const std::vector<math::vec3>& values);
    //void SetVectorArray (std::string location, int size, const std::vector<math::vec4>& values);
    //void SetMatrix      (std::string location, math::mat2 value);
    //void SetMatrix      (std::string location, math::mat3 value);
    void SetMatrix      (std::string_view location, glm::mat4 value);
    //void SetMatrixArray (std::string location, int size, math::mat2* values);
    //void SetMatrixArray (std::string location, int size, math::mat3* values);
    //void SetMatrixArray (std::string location, int size, math::mat4* values);
  private:
    unsigned int m_id;
  };
}