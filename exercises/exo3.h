#pragma once

#include "exercise.h"
#include "Files.h"

#include <glad/glad.h>

// Activity 3 - Element Indexing
//
// The four corners below are stored once. The index array describes the two
// triangles: (0, 1, 2) and (1, 3, 2).
class Exo3 : public Exercise
{
public:
    ~Exo3() override
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
        glDeleteProgram(m_shaderProgram);
    }

    void init() override
    {
        const float vertices[] = {
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f
        };
        const unsigned int indices[] = {0, 1, 2, 1, 3, 2};

        // TODO 1: create and upload both m_vbo and m_ebo.
        // TODO 2: reuse Activity 2's two attributes and attach m_ebo to m_vao.
        // TODO 3: compile/link shaders/exo3.vsh and shaders/exo3.fsh.
    }

    void render() override
    {
        // TODO: draw six indices with glDrawElements.
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;
    GLuint m_shaderProgram = 0;
};
