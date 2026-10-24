#ifndef RENDERER_H
#define RENDERER_H

#include "Window.h"

#include <SDL3/SDL_video.h>

class Renderer
{
public:
    Renderer(Window& window);
    ~Renderer();

    void beginFrame();
    void endFrame();
private:
    Window& m_window;
    SDL_GLContext m_glcontext;
};


#endif //RENDERER_H