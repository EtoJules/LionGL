#pragma once

#include "Core/Renderer/Renderer.h"
#include "Sandbox/Sandbox.h"
#include <iostream>

class TriangleSandbox : public Sandbox
{
private:
    VertexArray m_vertexArray;
    VertexBuffer m_vertexBuffer;
    VertexLayout m_vertexLayout;
    IndexBuffer m_indexBuffer;
    Shader m_shader;
    Renderer m_renderer{};

private:
    float m_vertices[3 * 6] =
    {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f // top
    };

    unsigned int m_index[2 * 3] =
    {
            0, 1, 2,
            2, 1, 2
    };

public:
    TriangleSandbox();

public:
    void start() final;
    void onUpdate(double deltaTime) final;

};