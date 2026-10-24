#include <iostream>

#include "Window.h"
#include "Renderer.h"

#include "exercises/exo1.h"

int main() {
    Window window("Opengl Workshop", 800, 600);
    Renderer renderer(window);

    //init exercise
    Exo1 exercise;
    exercise.init();

    while (!window.shouldClose())
    {
        window.pollEvents();
        renderer.beginFrame();

        // here to make the exercise render
        exercise.render();

        renderer.endFrame();
        window.swapBuffers();
    }

    return 0;
}