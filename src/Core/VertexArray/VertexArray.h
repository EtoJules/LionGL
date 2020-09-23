#pragma once

#include "VertexBuffer/VertexBuffer.h"
#include "VertexBuffer/VertexLayout.h"

class VertexArray
{
private:
    unsigned int m_RenderId;

public:
    VertexArray();
    ~VertexArray();

public:
    void bindArray(const VertexBuffer& vertexBuffer, const VertexLayout& vertexLayout);
    void bind() const;
    void unbind() const;
};