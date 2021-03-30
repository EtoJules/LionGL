#pragma once

#include <GL/glew.h>
#include <vector>
#include <iostream>

namespace oglite{
    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;

        static unsigned int getTypeSize(unsigned int type)
        {
            switch (type)
            {
            case GL_FLOAT:
                return 4;
            case GL_UNSIGNED_INT:
                return 4;
            default:
                return 0;
            }
        }
    };

    class VertexLayout
    {
    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;

    public:
        VertexLayout() : m_Stride(0) {}

    public:
        template <typename T>
        void push(unsigned int count);

        inline const std::vector<VertexBufferElement> getElements() const { return m_Elements; }
        inline unsigned int getStride() const { return m_Stride; }
    };
}