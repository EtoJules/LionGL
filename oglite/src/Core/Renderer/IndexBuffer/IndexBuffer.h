#pragma once

#include <GL/glew.h>
namespace oglite{
    class IndexBuffer
    {
    private:
        unsigned int m_RenderId;
        unsigned int m_Count;

    public:
        IndexBuffer();
        IndexBuffer(const void* data, unsigned int count);
        ~IndexBuffer();
        void bufferData(const void* data, unsigned int count);
        void bind() const;
        void unbind() const;
        unsigned int getCount() const;
    };
}