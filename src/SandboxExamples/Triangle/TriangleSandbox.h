#pragma once

#include "Core/Renderer/Renderer.h"
#include "Sandbox/Sandbox.h"
#include <iostream>

#include "imgui/imgui.h"

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
    void onGUI() final;
    void start() final;
    void onUpdate(double deltaTime) final;

};