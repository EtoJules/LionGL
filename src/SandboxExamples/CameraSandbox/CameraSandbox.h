#pragma once

#include "Core/Renderer/Renderer.h"
#include "Sandbox/Sandbox.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"

#include "Renderer/Texture/Texture.h"
#include "imgui/imgui.h"
#include <iostream>

class CameraSandbox : public Sandbox
{
private:
    VertexArray m_vertexArray;
    VertexBuffer m_vertexBuffer;
    VertexLayout m_vertexLayout;
    IndexBuffer m_indexBuffer;
    Texture m_texture;
    Shader m_shader;
    Renderer m_renderer{};

private:
    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;

public:
    CameraSandbox();

public:
    void start() final;
    void onUpdate(double deltaTime) final;
    void onGUI() final;
};