#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Renderer.h"
#include "IndexBuffer/IndexBuffer.h"

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LionGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to instantiate GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
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

    Shader shader("resources/shaders/vertex.glsl", "resources/shaders/fragment.glsl");
    shader.bind();

    Renderer render;
    while (!glfwWindowShouldClose(window))
    {
        render.clear();
        render.draw(vertexArray, indexBuffer, shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}