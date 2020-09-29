#pragma once

#include "Core/Renderer/Renderer.h"
#include "Sandbox/Sandbox.h"
#include "Core/Sandbox/Camera/Camera.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"

#include "Renderer/Texture/Texture.h"
#include "imgui/imgui.h"
#include <iostream>
#include <array>

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
    void start() final;
    void onUpdate(double deltaTime) final;
    void onEvent(const SDL_Event& event) final;
    void onGUI() final;
};