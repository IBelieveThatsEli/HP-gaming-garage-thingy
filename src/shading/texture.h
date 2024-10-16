#pragma once

#include <string_view>

namespace WhineEngine
{
  class Texture
  {
  public:
    Texture(const std::string_view filePath);
    ~Texture();

    void Use();
  private:
    unsigned int m_id;
  };
}