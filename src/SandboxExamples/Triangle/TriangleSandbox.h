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

public:
    TriangleSandbox();

public:
    void start() final;
    void onUpdate(double deltaTime) final;

};