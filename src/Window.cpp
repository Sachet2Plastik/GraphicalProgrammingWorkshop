#include "Window.h"

#include <stdexcept>
#include <string>


Window::Window(const std::string &title,const int w, const int h)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);

    m_window = SDL_CreateWindow(title.c_str(), w, h, SDL_WINDOW_OPENGL);

    if (!m_window) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("Window::Window - Window could not be created! SDL_Error: " + err);
    }


}

Window::~Window()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit(); // might need to look out for this if i ever use multiple windows
}

SDL_Window* Window::handle() const
{
    return m_window;
}

void Window::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED ||
            event.type == SDL_EVENT_QUIT) {
            m_shouldClose = true;
        }
    }
}

bool Window::shouldClose() const
{
    return m_shouldClose;
}

bool Window::swapBuffers()
{
    return SDL_GL_SwapWindow(m_window);
}