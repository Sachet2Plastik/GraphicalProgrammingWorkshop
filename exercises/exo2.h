#pragma once

#include "exercise.h"
#include "Files.h"

#include <glad/glad.h>

// Activity 2 - Adding Colors
//
// Start from Activity 1. The only new idea is a second vertex attribute and
// the matching shader interface. The six floats of each vertex are:
// position.x/y/z, then color.r/g/b.
class Exo2 : public Exercise
{
public:
    ~Exo2() override
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_shaderProgram);
    }

    void init() override
    {
        const float vertices[] = {
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
             0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
        };

        // TODO 1: repeat Activity 1's VBO/VAO setup with a 6-float stride.
        // TODO 2: describe location 0 as vec3 position and location 1 as
        // vec3 color. The color offset is 3 floats.

        // TODO 3: load shaders/exo2.vsh and shaders/exo2.fsh with
        // Files::loadFileContent, then compile and link the program.
    }

    void render() override
    {
        // TODO: bind the program and VAO, then draw the three vertices.
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_shaderProgram = 0;
};
