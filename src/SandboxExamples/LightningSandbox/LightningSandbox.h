#pragma once

#include "Sandbox/Sandbox.h"
#include "Renderer/Renderer.h"
#include "Sandbox/Camera/Camera.h"
#include "imgui/imgui.h"
#include <array>

class LightningSandbox : public Sandbox
{
private:
    VertexBuffer m_vertexBuffer;
    VertexLayout m_vertexLayout;
    VertexArray m_vertexArray;
    VertexArray m_lightVertexArray;
    IndexBuffer m_indexBuffer;
    Shader m_lightShader;
    Shader m_shader;
    Texture m_texture;

private:
    Renderer m_renderer{};
    Camera m_camera;

private:
    int m_mouseX;
    int m_mouseY;
    glm::vec3 cameraMoveVec;

public:
    LightningSandbox();

public:
    void start() override;
    void onUpdate(double deltaTime) override;
    void onEvent(const SDL_Event &event) override;
    void onGUI() override;
};