#define STB_IMAGE_IMPLEMENTATION

#include <GL/glew.h>
#include <iostream>

#include "SandboxExamples/MeshSandbox/MeshSandbox.h"
#include "SandboxExamples/LightningSandbox/LightningSandbox.h"
#include "SandboxExamples/TriangleSandbox/TriangleSandbox.h"
#include "SandboxExamples/CameraSandbox/CameraSandbox.h"
#include "GlWindow/GlWindow.h"

int main(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return -1;
    GlWindow window("LionGL",
                    1280, 720,
                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (glewInit() != GLEW_OK)
        std::cout << "Glew error!!! \n";

    window.loadSandbox(new MeshSandbox);
    window.startGameLoop();
    return 0;
}
