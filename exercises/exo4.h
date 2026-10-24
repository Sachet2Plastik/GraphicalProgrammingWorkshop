#pragma once

#include "exercise.h"
#include "Files.h"

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// Activity 4 - Textures
//
// This is Activity 3 with UV coordinates replacing colors. Each vertex is:
// position.x/y/z followed by texture.u/v.
class Exo4 : public Exercise
{
public:
    ~Exo4() override
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
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f
        };
        const unsigned int indices[] = {0, 1, 2, 1, 3, 2};

        // TODO 1: create and upload the VBO and EBO.
        // TODO 2: describe position at location 0 and UV at location 1.
        // TODO 3: create the texture, load assets/wall.jpg with stb_image,
        // upload it, and set its filtering/wrapping parameters.
        // TODO 4: load shaders/exo4.vsh and shaders/exo4.fsh with
        // Files::loadFileContent, then compile and link the program.
    }

    void render() override
    {
        // TODO: bind the shader, texture unit 0, and VAO.
        // Then draw the six indexed vertices.
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;
    GLuint m_texture = 0;
    GLuint m_shaderProgram = 0;
};
