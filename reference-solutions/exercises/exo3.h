#pragma once

#include "exercise.h"
#include "reference_helpers.h"

class Exo3 : public Exercise
{
public:
    ~Exo3() override
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
        glDeleteProgram(m_program);
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

        glCreateVertexArrays(1, &m_vao);
        glCreateBuffers(1, &m_vbo);
        glCreateBuffers(1, &m_ebo);
        glNamedBufferData(m_vbo, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glNamedBufferData(m_ebo, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexArrayVertexBuffer(m_vao, 0, m_vbo, 0, 6 * sizeof(float));
        glVertexArrayElementBuffer(m_vao, m_ebo);
        glVertexArrayAttribFormat(m_vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribFormat(m_vao, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
        glVertexArrayAttribBinding(m_vao, 0, 0);
        glVertexArrayAttribBinding(m_vao, 1, 0);
        glEnableVertexArrayAttrib(m_vao, 0);
        glEnableVertexArrayAttrib(m_vao, 1);
        m_program = makeReferenceProgram(
            "reference-solutions/shaders/exo3.vsh",
            "reference-solutions/shaders/exo3.fsh");
    }

    void render() override
    {
        glUseProgram(m_program);
        glBindVertexArray(m_vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;
    GLuint m_program = 0;
};
