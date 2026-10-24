#include "Renderer.h"

#include <stdexcept>
#include <cmath>

#include <glad/glad.h>

Renderer::Renderer(Window& window)
    : m_window(window)
{
    m_glcontext = SDL_GL_CreateContext(m_window.handle());

    if (!m_glcontext) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("Renderer::Renderer - OpenGL context could not be created! SDL_Error: " + err);
    }

    if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress)) == 0) {
        throw std::runtime_error("Failed to load OpenGL library.");
    }

    GLint context_flags = 0;
    glGetIntegerv(GL_CONTEXT_FLAGS, &context_flags);
    glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer()
{
    SDL_GL_DestroyContext(m_glcontext);
}

void Renderer::beginFrame()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::endFrame()
{

}
