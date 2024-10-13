#pragma once

#include "engine.h"

using namespace WhineEngine;

class Main : public App
{
public:
  Main();
  ~Main();

  void Start() override;
  void Update() override;
};