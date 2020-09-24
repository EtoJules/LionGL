#include "TriangleSandbox.h"

TriangleSandbox::TriangleSandbox()
    : m_shader("../src/SandboxExamples/Triangle/res/vertex.glsl",
        "../src/SandboxExamples/Triangle/res/fragment.glsl")
        {}

void TriangleSandbox::start()
{
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
}

void TriangleSandbox::onUpdate(double deltaTime)
{
    m_renderer.clear();
    m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
}
