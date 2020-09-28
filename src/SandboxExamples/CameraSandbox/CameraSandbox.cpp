#include "CameraSandbox.h"

CameraSandbox::CameraSandbox()
        : m_shader("../src/SandboxExamples/CameraSandbox/res/shaders/vertex.glsl",
                   "../src/SandboxExamples/CameraSandbox/res/shaders/fragment.glsl"),
          m_model(1.0f), m_view(1.0f), m_projection(1.0f)
{}

void CameraSandbox::start()
{
    //drawing triangle
    float vertices[] =
        {
                // positions          //texture coord
                -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

                -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };

    m_cubePositions =
        {
        glm::vec3( 0.0f, 0.0f,0.0f),
        glm::vec3( 2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f, 2.0f, -2.5f),
        glm::vec3( 1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
        };

    VertexBuffer::bufferData(vertices, sizeof(vertices));
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(2);
    m_vertexArray.bindArray(m_vertexBuffer, m_vertexLayout);

    unsigned int index[36];
    for (int i = 0; i < sizeof(index); i++)
        index[i] = i;
    m_indexBuffer.bufferData(index, sizeof(index));

    //texture
    m_texture.loadTexture("../src/SandboxExamples/CameraSandbox/res/textures/box.jpg");
    m_texture.bind(1);

    //mvp
    m_model = glm::rotate(m_model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
    m_projection = glm::perspective(45.0f, 1280.0f/720.0f, 0.1f, 100.0f);
    m_shader.setUniformMat4f("u_Model", m_model);
    m_shader.setUniformMat4f("u_View", m_view);
    m_shader.setUniformMat4f("u_Projection", m_projection);

    SDL_SetRelativeMouseMode(SDL_TRUE);
    //camera
    m_cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    m_time = 0;
}

void CameraSandbox::onUpdate(double deltaTime)
{
    m_renderer.clear();
    m_time += (float)deltaTime;

    //camera rotation
    //mouse
    SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);
    float deltaX = m_mouseX;
    float deltaY = m_mouseY;

    yaw += deltaX * deltaTime * 0.05f;
    pitch -= deltaY * deltaTime * 0.05f;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    m_cameraPosition += cameraMoveVec * (float)deltaTime;

    cameraFront = glm::normalize(direction);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 view;
    view = glm::lookAt(m_cameraPosition, m_cameraPosition + cameraFront, cameraUp);
    m_shader.setUniformMat4f("u_View", view);

    //drawing multiple cubes
    for(auto cubePosition : m_cubePositions)
    {
        glm::mat4 nModel = glm::translate(glm::mat4(1.0f), cubePosition);
        nModel = glm::rotate(nModel, (float) m_time * 0.0002f * (cubePosition.p + 1), glm::vec3(1.0f, 1.2f, 0.0f));
        m_shader.setUniformMat4f("u_Model", nModel);
        m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
    }
}

void CameraSandbox::onEvent(const SDL_Event &event)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_w:
                cameraMoveVec = 0.01f * cameraFront;
                break;
            case SDLK_s:
                cameraMoveVec = -0.01f * cameraFront;
                break;
            case SDLK_a:
                cameraMoveVec = -0.01f * glm::normalize(glm::cross(cameraFront, cameraUp));
                break;
            case SDLK_d:
                cameraMoveVec = 0.01f * glm::normalize(glm::cross(cameraFront, cameraUp));
                break;
            default:
                break;
        }
    }
    if(event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_w:
                cameraMoveVec = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            case SDLK_s:
                cameraMoveVec = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            case SDLK_a:
                cameraMoveVec = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            case SDLK_d:
                cameraMoveVec = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            default:
                break;
        }
    }
}

void CameraSandbox::onGUI()
{
    ImGui::Begin("FPS");
    ImGui::Text("Average %.3f ms (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}