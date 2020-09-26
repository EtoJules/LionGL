#include "TriangleSandbox.h"

TriangleSandbox::TriangleSandbox()
    : m_shader("../src/SandboxExamples/TriangleSandbox/res/vertex.glsl",
        "../src/SandboxExamples/TriangleSandbox/res/fragment.glsl"),
        m_model(1.0f), m_view(1.0f), m_projection(1.0f)
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
    m_model = glm::rotate(m_model, -50.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
    m_projection = glm::perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);

    m_shader.setUniformMat4f("u_Model", m_model);
    m_shader.setUniformMat4f("u_View", m_view);
    m_shader.setUniformMat4f("u_Projection", m_projection);
}

void TriangleSandbox::onUpdate(double deltaTime)
{
    m_renderer.clear();
    m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
}

void TriangleSandbox::onGUI()
{
    ImGui::Begin("FPS");
    ImGui::Text("Average %.3f ms (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}