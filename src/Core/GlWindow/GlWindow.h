#pragma  once
#include "Core/Sandbox/Sandbox.h"
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include <string>

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_opengl3.h"
#include "imgui/examples/imgui_impl_sdl.h"

class GlWindow{
private:
    SDL_Window *m_window;
    SDL_Event m_event{};
    SDL_GLContext m_glContext;
    Sandbox *m_sandbox;
    bool m_isWindowOpen;

public:
    GlWindow() = delete;
    GlWindow(const std::string &name, unsigned int width, unsigned int height, Uint32 flags);
    ~GlWindow();
    void loadSandbox(Sandbox* sandbox);
    void startGameLoop();
};