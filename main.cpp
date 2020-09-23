#include <GL/glew.h>
#include <iostream>
#include "SDL2/SDL.h"

#include "Core/Renderer/Renderer.h"

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("LionGL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);
    if (glewInit() != GLEW_OK)
        std::cout << "Glew error!!! \n";


    float vertices[] =
            {
                    // positions         // colors
                    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom right
                    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
                    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f // top
            };

    VertexArray vertexArray;
    VertexBuffer vertexBuffer(vertices, sizeof(vertices));
    VertexLayout vertexLayout;

    vertexLayout.push<float>(3);
    vertexLayout.push<float>(3);
    vertexArray.bindArray(vertexBuffer, vertexLayout);

    unsigned int index[] = {
            0, 1, 2,
            2, 1, 2
    };

    IndexBuffer indexBuffer(index, sizeof(index));

    Shader shader("../resources/shaders/vertex.glsl", "../resources/shaders/fragment.glsl");
    shader.bind();
    Renderer render;

    bool keep_window_open = true;
    SDL_Event e;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&e) > 0)
        {
            render.clear();
            render.draw(vertexArray, indexBuffer, shader);

            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
            SDL_GL_SwapWindow(window);
        }
    }
    return 0;
}