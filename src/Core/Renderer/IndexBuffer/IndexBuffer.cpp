#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count)
    : m_Count(count), m_RenderId(0)
{
    glGenBuffers(1, &m_RenderId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
}


IndexBuffer::IndexBuffer()
    : m_Count(0), m_RenderId(0)
{
    glGenBuffers(1, &m_RenderId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
}


IndexBuffer::~IndexBuffer() 
{
    glDeleteVertexArrays(1, &m_RenderId);
}

void IndexBuffer::bufferData(const void *data, unsigned int count)
{
    m_Count = count;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::getCount() const
{
    return m_Count;
}