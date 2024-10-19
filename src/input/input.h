#pragma once

#include "Window.h"
#include <map>
#include <vector>

namespace WhineEngine
{
  class KeyInput
  {
  public:
    KeyInput(std::vector<int> KeysToMonitor);
    ~KeyInput();

    bool GetEnabled() { return m_enabled; }
    
    void SetEnabled(bool enable) { m_enabled = enable; }

    bool GetKeyDown(int key);

    void SetKeyDown(int key, bool isDown);

    std::map<int, bool> m_keys;

    bool m_enabled;

    static void SetupKeyInputs(Window &window);
  private:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static std::vector<KeyInput*> m_instances;
  };
}