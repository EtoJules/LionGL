#include "Renderer.h"

void Renderer::clear() const{
    glClearColor(0.2f, 0.23f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
}
void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const{
    vertexArray.bind();
    indexBuffer.bind();
    shader.bind();
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::draw(const Mesh &mesh, const Shader &shader) const{
    mesh.getVertexArray().bind();
    mesh.getIndexBuffer().bind();
    shader.bind();
    glDrawElements(GL_TRIANGLES, mesh.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
}
