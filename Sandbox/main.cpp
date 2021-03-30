#define STB_IMAGE_IMPLEMENTATION

#include <GL/glew.h>
#include <iostream>

#include "SandboxExamples/MeshSandbox/MeshSandbox.h"
#include "GlWindow/GlWindow.h"

#undef main
int main(){
    GlWindow window("LionGL",
                    1280, 720,
                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    window.loadSandbox(new MeshSandbox);
    window.startGameLoop();
    return 0;
}
