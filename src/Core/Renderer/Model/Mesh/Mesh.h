#pragma once

#include <vector>
#include <utility>
#include <memory>
#include "Vertex/Vertex.h"
#include "Core/Renderer/VertexArray/VertexArray.h"
#include "Core/Renderer/IndexBuffer/IndexBuffer.h"
#include <Renderer/VertexBuffer/VertexBuffer.h>

class Mesh {
private:
    std::vector<Vertex> m_vertex;
    std::vector<uint> m_index;

    VertexBuffer m_vertexBuffer;
    VertexLayout m_vertexLayout;
    std::unique_ptr<VertexArray> m_vertexArray;
    std::unique_ptr<IndexBuffer> m_indexBuffer;

public:
    Mesh();
    Mesh(std::vector<Vertex> vertex, std::vector<uint> index);
    void loadMesh(const std::vector<Vertex> &vertex, const std::vector<uint> &index);
    void bind();
    VertexArray& getVertexArray() const;
    IndexBuffer& getIndexBuffer() const;
};

