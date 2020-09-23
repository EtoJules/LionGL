#pragma once

#include "Core/Renderer/VertexBuffer/VertexBuffer.h"
#include "Core/Renderer/VertexBuffer/VertexLayout.h"

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