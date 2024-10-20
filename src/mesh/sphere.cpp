/*

  CREATED: ELI PEFFER
  FOR: HP GAME JAM

*/  

// THANK U PIKACHUXXXX
//https://gist.github.com/Pikachuxxxx/5c4c490a7d7679824e0e18af42918efc

#include "sphere.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <glm/vec3.hpp>

using namespace WhineEngine;

Sphere::Sphere(int radius, int latitudes, int longitudes)
{
  if(longitudes < 3)
    longitudes = 3;
  if(latitudes < 2)
    latitudes = 2;

  std::vector<glm::vec3> vertices;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec2> uv;
  std::vector<unsigned int> indices;

  float nx, ny, nz, lengthInv = 1.0f / radius;

  struct Vertex
  {
    float x, y, z, s, t; // Postion and Texcoords
  };

  float deltaLatitude = M_PI / latitudes;
  float deltaLongitude = 2 * M_PI / longitudes;
  float latitudeAngle;
  float longitudeAngle;

  // Compute all vertices first except normals
  for (int i = 0; i <= latitudes; ++i)
  {
    latitudeAngle = M_PI / 2 - i * deltaLatitude; 
    float xy = radius * cosf(latitudeAngle);      
    float z = radius * sinf(latitudeAngle);       

    for (int j = 0; j <= longitudes; ++j)
    {
      longitudeAngle = j * deltaLongitude;

      Vertex vertex;
      vertex.x = xy * cosf(longitudeAngle);       
      vertex.y = xy * sinf(longitudeAngle);       
      vertex.z = z;                               
      vertex.s = (float)j/longitudes;             
      vertex.t = (float)i/latitudes;              
      vertices.push_back(glm::vec3(vertex.x, vertex.y, vertex.z));
      uv.push_back(glm::vec2(vertex.s, vertex.t));

      nx = vertex.x * lengthInv;
      ny = vertex.y * lengthInv;
      nz = vertex.z * lengthInv;
      normals.push_back(glm::vec3(nx, ny, nz));
    }
  }

  unsigned int k1, k2;
  for(int i = 0; i < latitudes; ++i)
  {
    k1 = i * (longitudes + 1);
    k2 = k1 + longitudes + 1;
    for(int j = 0; j < longitudes; ++j, ++k1, ++k2)
    {
      if (i != 0)
      {
        indices.push_back(k1);
        indices.push_back(k2);
        indices.push_back(k1 + 1);
      }

      if (i != (latitudes - 1))
      {
        indices.push_back(k1 + 1);
        indices.push_back(k2);
        indices.push_back(k2 + 1);
      }
    }
  }

  m_vertices = vertices;
  m_normals = normals;
  m_UV = uv;
  m_indices = indices;
}