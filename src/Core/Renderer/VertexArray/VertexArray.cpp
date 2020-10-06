#include "VertexArray.h"

VertexArray::VertexArray() 
{
    glGenVertexArrays(1, &m_RenderId);
    glBindVertexArray(m_RenderId);
}

VertexArray::~VertexArray() 
{
    glDeleteVertexArrays(1, &m_RenderId);
}

void VertexArray::bindArray(const VertexBuffer& vertexBuffer, const VertexLayout& vertexLayout) 
{
    glBindVertexArray(m_RenderId);
    const auto& elements = vertexLayout.getElements();
    unsigned int offset = 0;
    for(int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, vertexLayout.getStride(), (const void*)offset);
        offset += element.count * VertexBufferElement::getTypeSize(element.type);
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(m_RenderId);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}