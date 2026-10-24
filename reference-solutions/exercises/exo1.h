#pragma once

#include "exercise.h"
#include "reference_helpers.h"

class Exo1 : public Exercise
{
public:
    ~Exo1() override
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_program);
    }

    void init() override
    {
        const float vertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };

        glCreateVertexArrays(1, &m_vao);
        glCreateBuffers(1, &m_vbo);
        glNamedBufferData(m_vbo, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexArrayVertexBuffer(m_vao, 0, m_vbo, 0, 3 * sizeof(float));
        glVertexArrayAttribFormat(m_vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(m_vao, 0, 0);
        glEnableVertexArrayAttrib(m_vao, 0);
        m_program = makeReferenceProgram(
            "reference-solutions/shaders/exo1.vsh",
            "reference-solutions/shaders/exo1.fsh");
    }

    void render() override
    {
        glUseProgram(m_program);
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_program = 0;
};
