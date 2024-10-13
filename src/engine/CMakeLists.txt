add_library(engine STATIC 
  engine.cpp
  engine.h
)

target_include_directories(engine PUBLIC
  app.h
)