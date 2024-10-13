#pragma once

#include "app.h"

#include <memory>

namespace WhineEngine 
{
  class Engine {
  public:
    static Engine *Get() { return instance; }

    Engine();
    ~Engine();

    std::int32_t Run();

    App *GetApp() const { return app.get(); }

    void SetApp(std::unique_ptr<App> &&app) { this->app = std::move(app); }

    bool IsRunning() const { return running; }

    void RequestClose() { running = false; }
  private:
    static Engine *instance;

    bool running;
    
    std::unique_ptr<App> app;
  };
}