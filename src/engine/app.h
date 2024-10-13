#pragma once

#include <stdint.h>
#include <string>

namespace WhineEngine 
{
  class Version
  {
  public:
    Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch) :
      major{major}, minor{minor}, patch{patch} {

    }
    std::uint8_t major, minor, patch;
  };

  class App
  {
    friend class Engine;
  public:
    explicit App(std::string name, const Version &version = {1, 0, 0}) :
      m_name{name},
      m_version{version} {
        
    }

    virtual ~App() = default;

    virtual void Start() = 0;

    virtual void Update() = 0;

    const std::string &GetName() const { return m_name; }

    void SetName(const std::string& name) { this->m_name = name; }

    const Version &GetVersion() const { return m_version; }

    void SetVersion(const Version &version) { this->m_version = version; }

    bool HasStarted() const { return m_started; }

    void SetStarted() { m_started = true; }
  private:
    bool m_started{ false };
    std::string m_name;
    Version m_version;
  };
}