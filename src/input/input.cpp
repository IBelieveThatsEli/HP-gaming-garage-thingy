#include "input.h"

using namespace WhineEngine;

// I copied this code...
// here we hold an array of pInstances of the KeyInput class
std::vector<KeyInput*> KeyInput::m_instances;

KeyInput::KeyInput(std::vector<int> KeysToMonitor)
{
  for (int key : KeysToMonitor)
  {
    m_keys[key] = false;
  }

  KeyInput::m_instances.push_back(this);
}

KeyInput::~KeyInput()
{
  m_instances.erase(std::remove(m_instances.begin(), m_instances.end(), this), m_instances.end());
}

bool KeyInput::GetKeyDown(int key) {
  bool result = false;
  if (m_enabled) {
    std::map<int,bool>::iterator it = m_keys.find(key);
    if (it != m_keys.end())
      result = m_keys[key];
  }
  return result;
}

void KeyInput::SetKeyDown(int key, bool isDown) {
  std::map<int,bool>::iterator it = m_keys.find(key);
  if (it != m_keys.end())
    m_keys[key] = isDown;
}

void KeyInput::SetupKeyInputs(Window& window) {
  glfwSetKeyCallback(window.GetWindow(), KeyInput::key_callback);
}

void KeyInput::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  // Send key event to all KeyInput instances
  for (KeyInput* keyInput : m_instances) {
    keyInput->SetKeyDown(key, action != GLFW_RELEASE);
  }
}