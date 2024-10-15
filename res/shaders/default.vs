#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 camProjection;

out vec2 TexCoord;

void main() {
   gl_Position = camProjection * model * vec4(aPos, 1.0);
   TexCoord = aTexCoords;
}