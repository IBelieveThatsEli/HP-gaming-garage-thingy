#include "main.h"

#include "Window.h"

#include "scene.h"

int main()
{
  auto engine = std::make_unique<Engine>();
  engine->SetApp(std::make_unique<Main>());

  auto window = std::make_unique<Window>(800, 600, "Window");
  auto mainScene = std::make_unique<Scene>();

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
  Scene::Get()->addTriangle();
}

void Main::Update()
{
  if (Window::Get()->IsWindowOpen()) {
    Scene::Get()->Update();
    Window::Get()->Update();
  } else {
    Engine::Get()->RequestClose();
  }
}