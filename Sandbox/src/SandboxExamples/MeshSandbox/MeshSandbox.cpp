#include "MeshSandbox.h"

MeshSandbox::MeshSandbox()
    : m_shader("../Sandbox/src/SandboxExamples/MeshSandbox/res/shaders/vertex.glsl",
               "../Sandbox/src/SandboxExamples/MeshSandbox/res/shaders/fragment.glsl"),
      m_camera(0.0f, 100.0f, 150.0f),
      m_mouseX(0), m_mouseY(0), m_cameraMoveVec(0.0f, 0.0f, 0.0f),
      m_matildaModel("../Sandbox/src/SandboxExamples/MeshSandbox/res/models/matilda/matilda.fbx"),
      m_matildaTexture("../Sandbox/src/SandboxExamples/MeshSandbox/res/models/matilda/matilda.png"){}

void MeshSandbox::start(){
    //setting up mvp
    m_mvp.model = glm::rotate(m_mvp.model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    m_mvp.view = glm::translate(m_mvp.view, glm::vec3(0.0f, 0.0f, -3.0f));
    m_mvp.projection = glm::perspective(70.0f, 1920.0f/1080.0f, 0.1f, 10000.0f);
    m_shader.setUniformMat4f("u_Model", m_mvp.model);
    m_shader.setUniformMat4f("u_View", m_mvp.view);
    m_shader.setUniformMat4f("u_Projection", m_mvp.projection);
    m_matildaModel.addTexture(m_matildaTexture);

    SDL_SetRelativeMouseMode(SDL_TRUE);
    m_camera.setEulerAngle(-90, 0);
}

void MeshSandbox::onUpdate(double deltaTime){
    m_renderer.clear();

    //camera movement
    m_camera.setEulerAngle(m_camera.getYaw() + (m_mouseX * deltaTime * 0.005f),
                           m_camera.getPitch() - (m_mouseY * deltaTime * 0.005f));
    m_camera.setPosition(m_camera.getPosition() + m_cameraMoveVec * (float)deltaTime * 20.0f);
    m_shader.setUniformMat4f("u_View", m_camera.getLookAtMatrix());

    //mouse
    if(SDL_GetRelativeMouseMode() == SDL_TRUE) {
        SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);
    }else{
        m_mouseX = 0;
        m_mouseY = 0;
    }

    m_renderer.draw(m_matildaModel, m_shader);
}

void MeshSandbox::onGUI(){
    ImGui::Begin("DEBUG");
    ImGui::Text("Average %.3f ms (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::Text("Camera position:\n x %f y %f z %f",
                m_camera.getPosition().x, m_camera.getPosition().y, m_camera.getPosition().z);
    ImGui::Text("Press F to use mouse");
    ImGui::End();
}

void MeshSandbox::onEvent(const SDL_Event &event){
    if(event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym){
            case SDLK_w: m_cameraMoveVec = 0.01f * m_camera.getCameraFront(); break;
            case SDLK_s: m_cameraMoveVec = -0.01f * m_camera.getCameraFront(); break;
            case SDLK_a: m_cameraMoveVec = -0.01f * glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp())); break;
            case SDLK_d: m_cameraMoveVec = 0.01f * glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp())); break;
            case SDLK_f: SDL_SetRelativeMouseMode((bool)SDL_GetRelativeMouseMode() ? SDL_FALSE : SDL_TRUE); break;
            default: break;
        }
    }
    if(event.type == SDL_KEYUP){
        m_cameraMoveVec = glm::vec3(0.0f, 0.0f, 0.0f);
    }
}
