#pragma once

#include "exercise.h"
#include "Files.h"

#include <glad/glad.h>

// Activity 1 - Hello Triangle
//
// The goal is not to write everything from memory. The starter code below
// already gives you the objects and the vertex data. Complete one TODO at a
// time, using guides/exercise-1-hello-triangle.md as your map.
class Exo1 : public Exercise
{
public:
    ~Exo1() override
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_shaderProgram);
    }

    void init() override
    {
        // TODO: replace the empty array with three 3D positions for a triangle.
        // Hint: openGL treats the screen as a 2D plane from -1 to 1 in both X and Y. Z is ignored.
        const float vertices[] = {
            
        };

        // TODO 1: create m_vao and m_vbo, then upload vertices to m_vbo.
        // Hint: the buffer contains 3 floats per vertex.

        // TODO 2: describe attribute location 0 (a vec3 position) in m_vao.

        // TODO 3: load and compile shaders/exo1.vsh and shaders/exo1.fsh.
        // Files::loadFileContent(path) returns the complete shader source.

        // TODO 4: create m_shaderProgram, attach both shaders, and link it.
        // Delete the individual shader objects after linking.
    }

    void render() override
    {
        // TODO: use the shader program, bind the VAO, and draw 3 vertices.
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_shaderProgram = 0;
};
