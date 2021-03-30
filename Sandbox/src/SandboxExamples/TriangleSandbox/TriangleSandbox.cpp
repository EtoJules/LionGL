#include "TriangleSandbox.h"

TriangleSandbox::TriangleSandbox()
    : m_shader("../src/SandboxExamples/TriangleSandbox/res/shaders/vertex.glsl",
        "../src/SandboxExamples/TriangleSandbox/res/shaders/fragment.glsl"),
        m_model(1.0f), m_view(1.0f), m_projection(1.0f), m_camera(0.0f, 0.0f, 2.0f),
        m_mouseX(0), m_mouseY(0), cameraMoveVec(0.0f,0.0f,0.0f)
        {}

void TriangleSandbox::start()
{
    //drawing triangle
    float vertices[] =
    {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f // top
    };
    VertexBuffer::bufferData(vertices, sizeof(vertices));
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(3);
    m_vertexArray.bindArray(m_vertexBuffer, m_vertexLayout);
    unsigned int index[] =
    {
            0, 1, 2,
            2, 1, 2
    };
    m_indexBuffer.bufferData(index, sizeof(index));

    //setting up mvp
    m_model = glm::rotate(m_model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
    m_projection = glm::perspective(45.0f, 1280.0f/720.0f, 0.1f, 100.0f);
    m_shader.setUniformMat4f("u_Model", m_model);
    m_shader.setUniformMat4f("u_View", m_view);
    m_shader.setUniformMat4f("u_Projection", m_projection);

    //SDL_SetRelativeMouseMode(SDL_TRUE);
    m_camera.setEulerAngle(-90, 0);
}

void TriangleSandbox::onUpdate(double deltaTime)
{
    m_renderer.clear();

    //camera movement
    SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);
    m_camera.setEulerAngle(m_camera.getYaw() + (m_mouseX * deltaTime * 0.005f),
                           m_camera.getPitch() - (m_mouseY * deltaTime * 0.005f));
    m_camera.setPosition(m_camera.getPosition() + cameraMoveVec * (float)deltaTime);
    m_shader.setUniformMat4f("u_View", m_camera.getLookAtMatrix());

    m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
}

void TriangleSandbox::onGUI()
{
    ImGui::Begin("FPS");
    ImGui::Text("Average %.3f ms (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::Text("Camera position:\n x %f, y %f, z %f",
                m_camera.getPosition().x, m_camera.getPosition().y, m_camera.getPosition().z);
    ImGui::End();
}

void TriangleSandbox::onEvent(const SDL_Event &event) {
    if(event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_w:
                cameraMoveVec = 0.01f * m_camera.getCameraFront();
                break;
            case SDLK_s:
                cameraMoveVec = -0.01f * m_camera.getCameraFront();
                break;
            case SDLK_a:
                cameraMoveVec = -0.01f * glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp()));
                break;
            case SDLK_d:
                cameraMoveVec = 0.01f * glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp()));
                break;
            default:
                break;
        }
    }
    if(event.type == SDL_KEYUP)
    {
        cameraMoveVec = glm::vec3(0.0f, 0.0f, 0.0f);
    }
}
