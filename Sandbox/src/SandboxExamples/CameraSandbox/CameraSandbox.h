#pragma once

#include "Core/Sandbox/Camera/Camera.h"
#include "Sandbox/Sandbox.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"
#include "imgui/imgui.h"
#include "oglite.h"

#include <iostream>
#include <array>

class CameraSandbox : public Sandbox
{
private:
    oglite::VertexArray m_vertexArray;
    oglite::VertexBuffer m_vertexBuffer;
    oglite::VertexLayout m_vertexLayout;
    oglite::IndexBuffer m_indexBuffer;
    oglite::Texture m_texture;
    oglite::Shader m_shader;
    oglite::Renderer m_renderer{};

private:
    std::array<glm::vec3, 10> m_cubePositions;
    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;
    float m_time;

    Camera m_camera;
    float yaw;
    float pitch;
    glm::vec3 cameraMoveVec;

private:
    int m_mouseX;
    int m_mouseY;

public:
    CameraSandbox();

public:
    void start() override;
    void onUpdate(double deltaTime) override;
    void onEvent(const SDL_Event& event) override;
    void onGUI() final;
};