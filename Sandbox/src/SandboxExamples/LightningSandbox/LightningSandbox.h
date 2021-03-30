#pragma once

#include "Sandbox/Sandbox.h"
#include "oglite.h"
#include "Sandbox/Camera/Camera.h"
#include "imgui/imgui.h"
#include <array>

class LightningSandbox : public Sandbox
{
private:
    oglite::VertexBuffer m_vertexBuffer;
    oglite::VertexLayout m_vertexLayout;
    oglite::VertexArray m_vertexArray;
    oglite::VertexArray m_lightVertexArray;
    oglite::IndexBuffer m_indexBuffer;
    oglite::Shader m_lightShader;
    oglite::Shader m_shader;
    oglite::Texture m_texture;

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