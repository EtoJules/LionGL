#pragma once

#include <iostream>

#include "imgui/imgui.h"
#include "Sandbox/Sandbox.h"
#include "Core/Sandbox/Camera/MVP.h"
#include "Core/Sandbox/Camera/Camera.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"
#include "oglite.h"

class MeshSandbox: public Sandbox{
private:
    oglite::Model m_matildaModel;
    oglite::Texture m_matildaTexture;
    oglite::Shader m_shader;
    oglite::Renderer m_renderer;

    MVP m_mvp;
    Camera m_camera;

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
