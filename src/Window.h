#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>
#include <SDL3/SDL.h>


class Window
{
public:
    Window(const std::string &title, int w, int h);
    Window(Window &) = delete;
    ~Window();

    void pollEvents();
    bool shouldClose() const;
    bool swapBuffers();

    [[nodiscard]] SDL_Window* handle() const;

private:
    SDL_Window* m_window = nullptr;
    bool m_shouldClose = false;
};

#endif //WINDOW_H