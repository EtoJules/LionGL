#include "VertexBuffer.h"

oglite::VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    : m_RenderId(0)
{
    glGenBuffers(1, &m_RenderId);
    glBindBuffer(GL_ARRAY_BUFFER, m_RenderId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

oglite::VertexBuffer::VertexBuffer()
    : m_RenderId(0)
{
    glGenBuffers(1, &m_RenderId);
    glBindBuffer(GL_ARRAY_BUFFER, m_RenderId);
}

oglite::VertexBuffer::~VertexBuffer() 
{
    glDeleteBuffers(1, &m_RenderId);
}

void oglite::VertexBuffer::bufferData(const void *data, unsigned int size)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void oglite::VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RenderId);
}

void oglite::VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
