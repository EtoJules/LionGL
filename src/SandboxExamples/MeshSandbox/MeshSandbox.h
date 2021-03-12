#pragma once

#include <iostream>

#include "Sandbox/Sandbox.h"
#include "Core/Renderer/Renderer.h"
#include "Core/Sandbox/Camera/Camera.h"
#include "Core/Renderer/Model/Mesh/Mesh.h"
#include "Core/Renderer/Model/Model.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"

class MeshSandbox : public Sandbox{
private:
    Renderer m_renderer{};
    Shader m_shader;
    Model m_modelObject;

    Camera m_camera;
    int m_mouseX;
    int m_mouseY;
    glm::vec3 cameraMoveVec;

    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;

public:
    MeshSandbox();
    void start() final;
    void onUpdate(double deltaTime) final;
    void onEvent(const SDL_Event& event) final;
    void onGUI() final;
};
