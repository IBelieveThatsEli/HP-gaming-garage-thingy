/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/

#pragma once

#include "mesh.h"

namespace WhineEngine 
{
  class Sphere : public Mesh
  {
  public:
    Sphere(int radius, int latitudes, int longitudes);
  };
}