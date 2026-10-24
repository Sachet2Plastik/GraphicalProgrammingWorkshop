#pragma once

#include "exercise.h"
#include "Files.h"

#include <glad/glad.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <SDL3/SDL_timer.h>

// Activity 5 - Going 3D
//
// The cube data is provided. Focus on the new 3D concepts: shader matrices,
// animation, and depth testing. Follow guides/exercise-5-rotating-cube.md.
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

        // TODO 1: upload vertices and indices to the VBO and EBO.
        // TODO 2: configure the position/UV attributes and attach the EBO.
        // TODO 3: reuse Activity 4's texture setup.
        // TODO 4: compile/link shaders/exo5.vsh and shaders/exo5.fsh with
        // Files::loadFileContent, then query the three matrix uniforms.
    }

    void render() override
    {
        // TODO 5: create model, view, and projection matrices with GLM.
        // TODO 6: upload them, bind the texture and VAO, and draw 36 indices.
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
