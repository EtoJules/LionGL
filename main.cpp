#include <GL/glew.h>
#include <iostream>

#include "SandboxExamples/Triangle/TriangleSandbox.h"
#include "GlWindow/GlWindow.h"

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return -1;
    GlWindow window("LionGL",
                    800, 600,
                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (glewInit() != GLEW_OK)
        std::cout << "Glew error!!! \n";

    window.loadSandbox(new TriangleSandbox());
    window.startGameLoop();
    return 0;
}