#pragma once

#include "app.h"

#include <memory>

#include <ctime>

namespace WhineEngine 
{
  class Delta {
  public:
    Delta() : deltaTime{0.0f}, lastFrame{0.0f}, currentFrame{0.0f}
    {}
    void Update() {
      currentFrame = std::clock() / static_cast<float>(CLOCKS_PER_SEC);
      deltaTime = currentFrame - lastFrame;
      lastFrame = currentFrame;
    }
    float deltaTime, lastFrame, currentFrame;
  };

  class Engine {
  public:
    static Engine *Get() { return instance; }

    Engine();
    ~Engine();

    std::int32_t Run();

    App *GetApp() const { return app.get(); }

    void SetApp(std::unique_ptr<App> &&app) { this->app = std::move(app); }

    void SetDelta(std::unique_ptr<Delta> &&Delta) { this->delta = std::move(Delta); }

    void UpdateDelta() { delta->Update(); }

    float GetDeltaTime() { return delta->deltaTime; }

    bool IsRunning() const { return running; }

    void RequestClose() { running = false; }
  private:
    static Engine *instance;

    bool running;
    
    std::unique_ptr<App> app;

    std::unique_ptr<Delta> delta;
  };
}