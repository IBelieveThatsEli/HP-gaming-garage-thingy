#include "main.h"

#include <glad/glad.h>
#include <glm/vec3.hpp>

#include "Window.h"
#include "scene.h"
#include "input.h"

int main()
{
  auto engine = std::make_unique<Engine>();
  engine->SetApp(std::make_unique<Main>());
  engine->SetDelta(std::make_unique<Delta>());

  auto window = std::make_unique<Window>(800, 600, "Window");

  KeyInput input = std::vector<int> {
    GLFW_KEY_A,
    GLFW_KEY_D,
    GLFW_KEY_W,
    GLFW_KEY_S
  };

  input.SetupKeyInputs(*window);

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
  cube->CreateShader("../res/shaders/texture_vert.glsl", "../res/shaders/texture_frag.glsl");
  cube->CreateTexture("../res/textures/zuma.jpg");
  cube->SetOrientation(45.0f, glm::vec3(1.0f, 1.0f, 0.0f));

  auto lightSource = Scene::Get()->AddCube();
  lightSource->CreateBuffers();
  lightSource->CreateShader("../res/shaders/light_vert.glsl", "../res/shaders/light_frag.glsl");
  lightSource->SetPosition(glm::vec3(1.0f, 1.0f, 1.0f));
  lightSource->SetScale(glm::vec3(0.5f, 0.5f, 0.5f));

  struct Material {
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
  };

  struct Light {
    glm::vec3 position;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
  };

  Material material = {
    glm::vec3(1.0f, 0.5f, 0.31f),
    glm::vec3(1.0f, 0.5f, 0.31f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    32.0f
  };

  Light light = {
    Camera::Get()->GetPosition(),
    glm::vec3(0.2f, 0.2f, 0.2f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    glm::vec3(1.0f, 1.0f, 1.0f)
  };

  auto shader = cube->GetShader();
  shader.Use();
  shader.SetVector("material.ambient",  material.ambient);
  shader.SetVector("material.diffuse",  material.diffuse);
  shader.SetVector("material.specular", material.diffuse);
  shader.SetFloat("material.shininess", material.shininess);
    
  shader.SetVector("light.ambient",  0.2f, 0.2f, 0.2f);
  shader.SetVector("light.diffuse",  0.5f, 0.5f, 0.5f);
  shader.SetVector("light.specular", 1.0f, 1.0f, 1.0f); 
  shader.SetVector("light.position", lightSource->GetPosition());
  shader.SetVector("viewPos", Camera::Get()->GetPosition());
}

void Main::Update()
{
  if (!Window::Get()->IsWindowOpen()) Engine::Get()->RequestClose();
  
  Engine::Get()->UpdateDelta();
  Scene::Get()->Update();

  auto camera = Camera::Get();
  auto speed = (camera->GetCamSpeed() * Engine::Get()->GetDeltaTime());
  if (KeyInput::m_instances.at(0)->GetKeyDown(GLFW_KEY_W)) {
    camera->SetPosition(
      camera->GetPosition() + speed * camera->GetForward()
    );
  } 
  if (KeyInput::m_instances.at(0)->GetKeyDown(GLFW_KEY_S)) {
    camera->SetPosition(
      camera->GetPosition() - speed * camera->GetForward()
    );
  }
  if (KeyInput::m_instances.at(0)->GetKeyDown(GLFW_KEY_A)) {
    camera->SetPosition(
      camera->GetPosition() - glm::normalize(glm::cross(camera->GetForward(), camera->GetUp())) * speed
    );
  }
  if (KeyInput::m_instances.at(0)->GetKeyDown(GLFW_KEY_D)) {
    camera->SetPosition(
      camera->GetPosition() + glm::normalize(glm::cross(camera->GetForward(), camera->GetUp())) * speed
    );
  }


  Window::Get()->Update();
}