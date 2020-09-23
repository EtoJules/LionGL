#pragma once

#include <GL/glew.h>
#include "Shader/Shader.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "IndexBuffer/IndexBuffer.h"

class Renderer
{
private:
    unsigned int m_RenderId;

public:
    void draw(const VertexArray& vertexArray, const IndexBuffer& vertexBuffer, const Shader& shader);
    void clear();
};