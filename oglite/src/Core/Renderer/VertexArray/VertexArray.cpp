#include "VertexArray.h"

oglite::VertexArray::VertexArray() 
{
    glGenVertexArrays(1, &m_RenderId);
    glBindVertexArray(m_RenderId);
}

oglite::VertexArray::~VertexArray() 
{
    glDeleteVertexArrays(1, &m_RenderId);
}

void oglite::VertexArray::bindArray(const VertexBuffer& vertexBuffer, const VertexLayout& vertexLayout) 
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

void oglite::VertexArray::bind() const
{
    glBindVertexArray(m_RenderId);
}

void oglite::VertexArray::unbind() const
{
    glBindVertexArray(0);
}