#pragma once

#include "exercise.h"
#include "reference_helpers.h"

#include <glad/glad.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <SDL3/SDL_timer.h>

#include <stdexcept>

class Exo5 : public Exercise
{
public:
    ~Exo5() override
    {
        glDeleteTextures(1, &m_texture);
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
        glDeleteProgram(m_shaderProgram);
    }

    void init() override
    {
        const float vertices[] = {
            // Front
            -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
             0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
             0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
            // Back
             0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
             0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
            // Left
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
            // Right
             0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
             0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
             0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
            // Top
            -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
             0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
            // Bottom
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
             0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
             0.5f, -0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f,  0.5f, 0.0f, 1.0f
        };
        const unsigned int indices[] = {
             0,  1,  2,  2,  3,  0,
             4,  5,  6,  6,  7,  4,
             8,  9, 10, 10, 11,  8,
            12, 13, 14, 14, 15, 12,
            16, 17, 18, 18, 19, 16,
            20, 21, 22, 22, 23, 20
        };

        glCreateVertexArrays(1, &m_vao);
        glCreateBuffers(1, &m_vbo);
        glCreateBuffers(1, &m_ebo);
        glNamedBufferData(m_vbo, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glNamedBufferData(m_ebo, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexArrayVertexBuffer(m_vao, 0, m_vbo, 0, 5 * sizeof(float));
        glVertexArrayAttribFormat(m_vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribFormat(m_vao, 1, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
        glVertexArrayAttribBinding(m_vao, 0, 0);
        glVertexArrayAttribBinding(m_vao, 1, 0);
        glEnableVertexArrayAttrib(m_vao, 0);
        glEnableVertexArrayAttrib(m_vao, 1);
        glVertexArrayElementBuffer(m_vao, m_ebo);

        glCreateTextures(GL_TEXTURE_2D, 1, &m_texture);
        stbi_set_flip_vertically_on_load(true);
        int width = 0, height = 0, channels = 0;
        unsigned char* data = stbi_load("assets/wall.jpg", &width, &height, &channels, 3);
        if (data == nullptr)
            throw std::runtime_error("Could not load assets/wall.jpg");
        glTextureStorage2D(m_texture, 1, GL_RGB8, width, height);
        glTextureSubImage2D(m_texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        glTextureParameteri(m_texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        m_shaderProgram = makeReferenceProgram(
            "reference-solutions/shaders/exo5.vsh",
            "reference-solutions/shaders/exo5.fsh");
        m_modelLocation = glGetUniformLocation(m_shaderProgram, "model");
        m_viewLocation = glGetUniformLocation(m_shaderProgram, "view");
        m_projectionLocation = glGetUniformLocation(m_shaderProgram, "projection");
        const GLint textureLocation =
            glGetUniformLocation(m_shaderProgram, "ourTexture");
        glUseProgram(m_shaderProgram);
        glUniform1i(textureLocation, 0);
    }

    void render() override
    {
        const float time = static_cast<float>(SDL_GetTicks()) / 1000.0f;
        const glm::mat4 model = glm::rotate(glm::mat4(1.0f), time, glm::vec3(0.7f, 1.0f, 0.2f));
        const glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.5f));
        const glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glUseProgram(m_shaderProgram);
        glUniformMatrix4fv(m_modelLocation, 1, GL_FALSE, &model[0][0]);
        glUniformMatrix4fv(m_viewLocation, 1, GL_FALSE, &view[0][0]);
        glUniformMatrix4fv(m_projectionLocation, 1, GL_FALSE, &projection[0][0]);
        glBindTextureUnit(0, m_texture);
        glBindVertexArray(m_vao);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;
    GLuint m_texture = 0;
    GLuint m_shaderProgram = 0;
    GLint m_modelLocation = -1;
    GLint m_viewLocation = -1;
    GLint m_projectionLocation = -1;
};
