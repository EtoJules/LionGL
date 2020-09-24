#include "TriangleSandbox.h"

TriangleSandbox::TriangleSandbox()
    : m_shader("../src/SandboxExamples/Triangle/res/vertex.glsl",
        "../src/SandboxExamples/Triangle/res/fragment.glsl"){}

void TriangleSandbox::start()
{
    VertexBuffer::bufferData(m_vertices, sizeof(m_vertices));
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(3);
    m_vertexArray.bindArray(m_vertexBuffer, m_vertexLayout);
    m_indexBuffer.bufferData(m_index, sizeof(m_index));
}

void TriangleSandbox::onUpdate(double deltaTime)
{
    std::cout << deltaTime << std::endl;
    m_renderer.clear();
    m_renderer.draw(m_vertexArray, m_indexBuffer, m_shader);
}
