#pragma once

#include <GL/glew.h>

class IndexBuffer
{
private:
    unsigned int m_RenderId;
    unsigned int m_Count;

public:
    IndexBuffer(const void* data, unsigned int size);
    ~IndexBuffer();

public:
    void bind() const;
    void unbind() const;
    unsigned int getCount() const;
};