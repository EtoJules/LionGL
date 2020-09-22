#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL++", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to instantiate GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
        std::cout << "Glew error!!! \n";

    unsigned int vertexArray;
    glCreateBuffers(1, &vertexArray);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}