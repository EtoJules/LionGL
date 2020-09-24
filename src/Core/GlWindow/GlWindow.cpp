#include "GlWindow.h"

GlWindow::GlWindow(const std::string& name, unsigned int width, unsigned int height, Uint32 flags)
    : m_isWindowOpen(true)
{
    m_window = SDL_CreateWindow(name.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, width, height, flags);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    m_glContext = SDL_GL_CreateContext(m_window);
    m_sandbox = new Sandbox();

    // setting up imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsClassic();
    ImGui_ImplSDL2_InitForOpenGL(m_window, m_glContext);
    ImGui_ImplOpenGL3_Init("#version 150");
}

GlWindow::~GlWindow()
{
    delete m_sandbox;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void GlWindow::loadSandbox(Sandbox* sandbox)
{
    delete m_sandbox;
    m_sandbox = sandbox;
}

void GlWindow::startGameLoop()
{
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double deltaTime = 0;

    m_sandbox->start();
    while(m_isWindowOpen)
    {
        while(SDL_PollEvent(&m_event) > 0)
        {
            ImGui_ImplSDL2_ProcessEvent(&m_event);
            if (m_event.type == SDL_WINDOWEVENT && m_event.window.event == SDL_WINDOWEVENT_CLOSE &&
                m_event.window.windowID == SDL_GetWindowID(m_window))
            {
                m_isWindowOpen = false;
            }

            switch(m_event.type)
            {
                case SDL_QUIT:
                    m_isWindowOpen = false;
                    break;
            }
        }
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(m_window);
        ImGui::NewFrame();

        {
            m_sandbox->onGUI();
        }

        ImGui::Render();
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = (double) ((now - last) * 1000 / (double) SDL_GetPerformanceFrequency());
        m_sandbox->onUpdate(deltaTime);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(m_window);
    }
}