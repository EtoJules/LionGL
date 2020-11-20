#pragma once

#include <GL/glew.h>
#include "Core/Renderer/Shader/Shader.h"
#include "Core/Renderer/VertexBuffer/VertexBuffer.h"
#include "Core/Renderer/VertexArray/VertexArray.h"
#include "Core/Renderer/IndexBuffer/IndexBuffer.h"
#include "Core/Renderer/Texture/Texture.h"

class Renderer
{
private:
    unsigned int m_RenderId;

public:
    void draw(const VertexArray& vertexArray, const IndexBuffer& vertexBuffer, const Shader& shader) const;
    void clear() const;
};