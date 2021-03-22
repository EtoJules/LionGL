#pragma once

#include <iostream>

#include "Sandbox/Sandbox.h"
#include "Core/Renderer/Renderer.h"
#include "Core/Sandbox/Camera/Camera.h"
#include "Sandbox/Camera/MVP.h"
#include "Core/Renderer/Model/Mesh/Mesh.h"
#include "Core/Renderer/Model/Model.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"

class MeshSandbox : public Sandbox{
private:
    Model m_matildaModel;
    Texture m_matildaTexture;
    Shader m_shader;
    Renderer m_renderer;

    Camera m_camera;
    MVP m_mvp;

    glm::vec3 m_cameraMoveVec;
    int m_mouseX;
    int m_mouseY;

public:
    MeshSandbox();
    void start() final;
    void onUpdate(double deltaTime) final;
    void onEvent(const SDL_Event& event) final;
    void onGUI() final;
};
