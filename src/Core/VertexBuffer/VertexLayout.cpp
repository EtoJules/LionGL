#include "VertexLayout.h"

template<>
void VertexLayout::push<float>(unsigned int count) 
{
	m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
	m_Stride += VertexBufferElement::getTypeSize(GL_FLOAT) * count;
}

template<>
void VertexLayout::push<unsigned int>(unsigned int count)
{
	m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE });
	m_Stride += VertexBufferElement::getTypeSize(GL_UNSIGNED_INT) * count;
}