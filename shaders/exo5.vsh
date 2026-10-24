#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;

out vec2 UV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // TODO: transform the vertex from model space to clip space.
    // TODO: forward the texture coordinates.
}
