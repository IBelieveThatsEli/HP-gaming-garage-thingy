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
  auto cam = Scene::Get()->AddCamera();

  auto cube = Scene::Get()->AddCube();
  cube->CreateBuffers();
  cube->CreateShader("../res/shaders/default_vert.glsl", "../res/shaders/default_frag.glsl");
  cube->SetOrientation(45.0f, glm::vec3(1.0f, 1.0f, 0.0f));

  auto lightSource = Scene::Get()->AddCube();
  lightSource->CreateBuffers();
  lightSource->CreateShader("../res/shaders/light_vert.glsl", "../res/shaders/light_frag.glsl");
  lightSource->SetPosition(glm::vec3(1.0f, 0.5f, 0.75f));
  lightSource->SetScale(glm::vec3(0.5f, 0.5f, 0.5f));

  auto shader = cube->GetShader();
  shader.Use();
  shader.SetVector("objectColor", 1.0f, 0.5f, 0.31f);
  shader.SetVector("lightColor",  1.0f, 1.0f, 1.0f);
  shader.SetVector("lightPos", lightSource->GetPosition());
  shader.SetVector("viewPos", Camera::Get()->GetPosition());
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