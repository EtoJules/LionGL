#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
    unsigned int m_RenderId;

public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

public:
    static void bufferData(const void* data, unsigned int size);
    void bind() const;
    void unbind() const;
};