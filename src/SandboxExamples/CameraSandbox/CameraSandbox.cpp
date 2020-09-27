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
            // positions    //colors            //texture coord
        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
         0.5f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
        };

    VertexBuffer::bufferData(vertices, sizeof(vertices));
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(2);
    m_vertexArray.bindArray(m_vertexBuffer, m_vertexLayout);
    unsigned int index[] =
    {
           0, 1, 2,
           2, 3, 0
    };
    m_indexBuffer.bufferData(index, sizeof(index));

    //texture
    m_texture.loadTexture("../src/SandboxExamples/CameraSandbox/res/textures/box.jpg");
    m_texture.bind(1);

    //setting up mvp
    m_model = glm::rotate(m_model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
    m_projection = glm::perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);

    m_shader.setUniformMat4f("u_Model", m_model);
    m_shader.setUniformMat4f("u_View", m_view);
    m_shader.setUniformMat4f("u_Projection", m_projection);
}

void CameraSandbox::onUpdate(double deltaTime)
{
    m_renderer.clear();
    m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
}

void CameraSandbox::onGUI()
{
    ImGui::Begin("FPS");
    ImGui::Text("Average %.3f ms (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}