#include "Mesh.h"

Mesh::Mesh(){
    m_vertexArray = std::make_unique<VertexArray>();
    m_indexBuffer = std::make_unique<IndexBuffer>();
}

Mesh::Mesh(std::vector<Vertex> vertex, std::vector<uint> index)
: m_vertex(std::move(vertex)), m_index(std::move(index)){
    m_vertexArray = std::make_unique<VertexArray>();
    m_indexBuffer = std::make_unique<IndexBuffer>();
}

void Mesh::loadMesh(const std::vector<Vertex> &vertex, const std::vector<uint> &index) {
    m_vertex = vertex;
    m_index = index;
}

void Mesh::bind() {
    VertexBuffer::bufferData(m_vertex.data(), m_vertex.size() * sizeof(Vertex));
    m_vertexLayout.push<float>(3);
    m_vertexLayout.push<float>(3);

    m_vertexArray->bindArray(m_vertexBuffer, m_vertexLayout);
    m_indexBuffer->bufferData(m_index.data(), sizeof(m_index));
}

VertexArray& Mesh::getVertexArray() const {
    return *m_vertexArray;
}

IndexBuffer& Mesh::getIndexBuffer() const {
    return *m_indexBuffer;
}
