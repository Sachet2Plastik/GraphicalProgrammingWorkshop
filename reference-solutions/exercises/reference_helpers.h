#pragma once

#include "Files.h"

#include <glad/glad.h>

#include <stdexcept>
#include <string>

inline GLuint makeReferenceProgram(const char* vertexPath, const char* fragmentPath)
{
    const auto compile = [](GLenum type, const char* path) {
        const std::string source = Files::loadFileContent(path);
        const char* text = source.c_str();
        const GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &text, nullptr);
        glCompileShader(shader);
        GLint success = GL_FALSE;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE) {
            char log[1024] = {};
            glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
            glDeleteShader(shader);
            throw std::runtime_error(
                std::string("Could not compile ") + path + ":\n" + log);
        }
        return shader;
    };
    const GLuint vertex = compile(GL_VERTEX_SHADER, vertexPath);
    const GLuint fragment = compile(GL_FRAGMENT_SHADER, fragmentPath);
    const GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    GLint success = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        char log[1024] = {};
        glGetProgramInfoLog(program, sizeof(log), nullptr, log);
        glDeleteProgram(program);
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        throw std::runtime_error(
            std::string("Could not link reference program:\n") + log);
    }
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return program;
}
