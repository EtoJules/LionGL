#include "IndexBuffer.h"

oglite::IndexBuffer::IndexBuffer(const void* data, unsigned int count)
    : m_Count(count), m_RenderId(0)
{
    glGenBuffers(1, &m_RenderId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
}


oglite::IndexBuffer::IndexBuffer()
    : m_Count(0), m_RenderId(0)
{
    glGenBuffers(1, &m_RenderId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
}


oglite::IndexBuffer::~IndexBuffer() 
{
    glDeleteVertexArrays(1, &m_RenderId);
}

void oglite::IndexBuffer::bufferData(const void *data, unsigned int count)
{
    m_Count = count;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
}

void oglite::IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
}

void oglite::IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int oglite::IndexBuffer::getCount() const
{
    return m_Count;
}