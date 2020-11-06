#include <X11/Xmd.h>
#include "LightningSandbox.h"

LightningSandbox::LightningSandbox()
: m_shader("../src/SandboxExamples/LightningSandbox/res/shaders/vertex.glsl",
               "../src/SandboxExamples/LightningSandbox/res/shaders/fragment.glsl"),
               m_lightShader("../src/SandboxExamples/LightningSandbox/res/shaders/vertex.glsl",
                             "../src/SandboxExamples/LightningSandbox/res/shaders/fragmentLight.glsl"),
               m_camera(-1.5f, 0.0f, -3.0f){}

void LightningSandbox::start()
{
    float vert[] =
            {
                //positions             //normals
                -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,
                0.5f, -0.5f, -0.5f,     0.0f, 0.0f, -1.0f,
                0.5f,  0.5f, -0.5f,     0.0f, 0.0f, -1.0f,
                0.5f,  0.5f, -0.5f,     0.0f, 0.0f, -1.0f,
                -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,
                -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,

                -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
                0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
                0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
                0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
                -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
                -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,

                -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,

                0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,
                0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
                0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,
                0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,

                -0.5f, -0.5f, -0.5f,    0.0f, -1.0f, 0.0f,
                0.5f, -0.5f, -0.5f,     0.0f, -1.0f, 0.0f,
                0.5f, -0.5f,  0.5f,     0.0f, -1.0f, 0.0f,
                0.5f, -0.5f,  0.5f,     0.0f, -1.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,     0.0f, -1.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,     0.0f, -1.0f, 0.0f,

                -0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
            };
    VertexBuffer::bufferData(vert, sizeof(vert));
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(3);
    m_vertexArray.bindArray(m_vertexBuffer, m_vertexLayout);
    m_lightVertexArray.bindArray(m_vertexBuffer, m_vertexLayout);
    unsigned int index[36];
    for (int i = 0; i < 36; i++)
    {
        index[i] = i;
    }
    m_indexBuffer.bufferData(index, sizeof(index));

    //material setup
    m_shader.setUniform4f("u_material.ambient", 1.0f, 0.5f, 0.31f, 1.0f );
    m_shader.setUniform4f("u_material.diffuse", 1.0f, 0.5f, 0.31f, 1.0f );
    m_shader.setUniform4f("u_material.specular", 1.0f, 0.5f, 0.31f, 1.0f );
    m_shader.setUniform1f("u_material.shininess", 32.0f);

    //color
    m_shader.setUniform4f("u_ObjectColor", 1.0f, 0.5f, 0.31f, 1.0f);
    m_shader.setUniform4f("u_LightColor", 1.0f, 1.0f, 1.0f, 1.0f);

    //MVP
    glm::mat4 model(1.0f);
    glm::mat4 view(1.0f);
    glm::mat4 projection(1.0f);
    model = glm::rotate(model, 45.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    projection = glm::perspective(45.0f, 1280.0f/720.0f, 0.1f, 100.0f);
    m_shader.setUniformMat4f("u_Model", model);
    m_shader.setUniformMat4f("u_Projection", projection);
    m_lightShader.setUniformMat4f("u_Model", model);
    m_lightShader.setUniformMat4f("u_Projection", projection);

    SDL_SetRelativeMouseMode(SDL_TRUE);
    m_camera.setEulerAngle(90, -10);
    m_shader.setUniformMat4f("u_View", m_camera.getLookAtMatrix());
    m_lightShader.setUniformMat4f("u_View", m_camera.getLookAtMatrix());

    m_shader.setUniform4f("u_LightPosition", 1.5f, -0.2f, -1.0f, 1.0f);
}

void LightningSandbox::onUpdate(double deltaTime)
{
    m_renderer.clear();
    SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);
    m_camera.setEulerAngle(m_camera.getYaw() + (m_mouseX * deltaTime * 0.005f),
                           m_camera.getPitch() - (m_mouseY * deltaTime * 0.005f));
    m_camera.setPosition(m_camera.getPosition() + cameraMoveVec * (float)deltaTime);
    m_shader.setUniformMat4f("u_View", m_camera.getLookAtMatrix());
    m_lightShader.setUniformMat4f("u_View",m_camera.getLookAtMatrix());
    //draw cube objects
    {
        glm::mat4 nModel = glm::translate(glm::mat4(1.0f), glm::vec3(-1.3f, -1.0f, 2.0f));
        m_shader.setUniformMat4f("u_Model", nModel);
        m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
    }
    //draw lights
    {
        glm::mat4 nModel = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f, -0.2f, -1.0f));
        m_lightShader.setUniformMat4f("u_Model", nModel);
        m_renderer.draw(m_lightVertexArray, m_indexBuffer, m_lightShader);
    }
}

void LightningSandbox::onGUI()
{
    ImGui::Begin("FPS");
    ImGui::Text("Average %.3f ms (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}

void LightningSandbox::onEvent(const SDL_Event &event)
{
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
                cameraMoveVec = -0.01f * glm::normalize(glm::cross(m_camera.getCameraFront(),m_camera.getCameraUp()));
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
