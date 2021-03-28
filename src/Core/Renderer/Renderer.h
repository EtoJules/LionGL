#pragma once

#include <GL/glew.h>
#include "Core/Renderer/Shader/Shader.h"
#include "Core/Renderer/VertexBuffer/VertexBuffer.h"
#include "Core/Renderer/VertexArray/VertexArray.h"
#include "Core/Renderer/IndexBuffer/IndexBuffer.h"
#include "Core/Renderer/Texture/Texture.h"
#include "Renderer/Model/Mesh/Mesh.h"
#include "Renderer/Model/Model.h"

using uint = unsigned int;

class Renderer{
private:
    unsigned int m_RenderId;

public:
    void draw(const VertexArray &vertexArray, const IndexBuffer &vertexBuffer, const Shader &shader) const;
    void draw(const Mesh &mesh, const Shader &shader) const;
    void draw(Model &model, const Shader &shader) const;
    void clear() const;
};