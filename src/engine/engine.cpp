#include "engine.h"

using namespace WhineEngine;

Engine *Engine::instance = nullptr;
Engine::Engine() :
  running{true}
{
  instance = this;
}

Engine::~Engine()
{
  app = nullptr;
}

std::int32_t Engine::Run()
{
  while (running) 
  {
    if (app) 
    {
      if (!app->HasStarted())
      {
        app->Start();
        app->SetStarted();
      }

      app->Update();
    }
  }
  return EXIT_SUCCESS;
}
