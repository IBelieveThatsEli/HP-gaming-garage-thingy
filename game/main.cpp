#include "main.h"

#include "Window.h"

#include "scene.h"

#include <glad/glad.h>

#include <glm/vec3.hpp>

int main()
{
  auto engine = std::make_unique<Engine>();
  engine->SetApp(std::make_unique<Main>());

  auto window = std::make_unique<Window>(800, 600, "Window");
  auto scene = std::make_unique<Scene>();

  auto exitCode = engine->Run();

  return exitCode;
}

Main::Main()
  : App("Project", {1, 0, 0})
{

}

Main::~Main()
{

}

void Main::Start()
{
  auto cube = Scene::Get()->AddCube();
  cube->CreateBuffers();
  cube->SetScale(glm::vec3(1.0f, 2.0f, 1.0f));
  cube->SetPosition(glm::vec3(-1.5f, 0.0f, 0.0f));

  auto cube2 = Scene::Get()->AddCube();
  cube2->CreateBuffers();
}

void Main::Update()
{
  if (Window::Get()->IsWindowOpen()) {
    Scene::Get()->Update();
    // Scenes::Get()->UpdateScenes();
    Window::Get()->Update();
  } else {
    Engine::Get()->RequestClose();
  }
}