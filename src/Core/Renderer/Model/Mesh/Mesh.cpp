#include "Mesh.h"

Mesh::Mesh() : m_vertex(0), m_index(0){
    initPointers();
    bind();
}

Mesh::Mesh(std::vector<Vertex> vertex, std::vector<uint> index)
: m_vertex(std::move(vertex)), m_index(std::move(index)){
    initPointers();
    bind();
}

void Mesh::bind() {
    VertexBuffer::bufferData(m_vertex.data(), m_vertex.size() * sizeof(Vertex));
    m_vertexLayout->push<float>(3);
    m_vertexLayout->push<float>(3);
    m_vertexLayout->push<float>(2);

    m_vertexArray->bindArray(*m_vertexBuffer, *m_vertexLayout);
    m_indexBuffer->bufferData(m_index.data(), m_index.size() * sizeof(uint));
}

void Mesh::initPointers() {
    m_vertexBuffer = std::make_unique<VertexBuffer>();
    m_vertexLayout = std::make_unique<VertexLayout>();
    m_vertexArray = std::make_unique<VertexArray>();
    m_indexBuffer = std::make_unique<IndexBuffer>();
}