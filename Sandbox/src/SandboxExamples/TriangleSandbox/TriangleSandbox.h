#pragma once

#include "Sandbox/Sandbox.h"
#include "imgui/imgui.h"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>
#include "oglite.h"

class TriangleSandbox : public Sandbox
{
private:
    oglite::VertexArray m_vertexArray;
    oglite::VertexBuffer m_vertexBuffer;
    oglite::VertexLayout m_vertexLayout;
    oglite::IndexBuffer m_indexBuffer;
    oglite::Shader m_shader;
    oglite::Renderer m_renderer{};

    Camera m_camera;
    int m_mouseX;
    int m_mouseY;
    glm::vec3 cameraMoveVec;

    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;

public:
    TriangleSandbox();

public:
    void start() final;
    void onUpdate(double deltaTime) final;
    void onEvent(const SDL_Event& event) final;
    void onGUI() final;
};