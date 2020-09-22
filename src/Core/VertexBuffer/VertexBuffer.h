#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
    unsigned int m_RenderId;

public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

public:
    void bind();
    void unbind();
};