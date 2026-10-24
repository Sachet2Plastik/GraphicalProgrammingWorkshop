#pragma once

#include "exercise.h"
#include "reference_helpers.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class Exo4 : public Exercise
{
public:
    ~Exo4() override
    {
        glDeleteTextures(1, &m_texture);
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
        glDeleteProgram(m_program);
    }

    void init() override
    {
        const float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f
        };
        const unsigned int indices[] = {0, 1, 2, 1, 3, 2};

        glCreateVertexArrays(1, &m_vao);
        glCreateBuffers(1, &m_vbo);
        glCreateBuffers(1, &m_ebo);
        glNamedBufferData(m_vbo, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glNamedBufferData(m_ebo, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexArrayVertexBuffer(m_vao, 0, m_vbo, 0, 5 * sizeof(float));
        glVertexArrayElementBuffer(m_vao, m_ebo);
        glVertexArrayAttribFormat(m_vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribFormat(m_vao, 1, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
        glVertexArrayAttribBinding(m_vao, 0, 0);
        glVertexArrayAttribBinding(m_vao, 1, 0);
        glEnableVertexArrayAttrib(m_vao, 0);
        glEnableVertexArrayAttrib(m_vao, 1);

        int width = 0;
        int height = 0;
        int channels = 0;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(
            "assets/wall.jpg", &width, &height, &channels, 3);
        if (data == nullptr) {
            throw std::runtime_error("Could not load assets/wall.jpg");
        }
        glCreateTextures(GL_TEXTURE_2D, 1, &m_texture);
        glTextureStorage2D(m_texture, 1, GL_RGB8, width, height);
        glTextureSubImage2D(m_texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        glTextureParameteri(m_texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        m_program = makeReferenceProgram(
            "reference-solutions/shaders/exo4.vsh",
            "reference-solutions/shaders/exo4.fsh");
        const GLint textureLocation =
            glGetUniformLocation(m_program, "ourTexture");
        glUseProgram(m_program);
        glUniform1i(textureLocation, 0);
    }

    void render() override
    {
        glUseProgram(m_program);
        glBindTextureUnit(0, m_texture);
        glBindVertexArray(m_vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;
    GLuint m_texture = 0;
    GLuint m_program = 0;
};
