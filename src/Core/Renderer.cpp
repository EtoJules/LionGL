#include "Renderer.h"


void Renderer::clear() 
{
    glClearColor(0.2f, 0.23f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}   
void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) 
{
    vertexArray.bind();
    indexBuffer.bind();
    shader.bind();
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr);
}
