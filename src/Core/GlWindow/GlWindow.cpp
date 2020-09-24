#include "GlWindow.h"

GlWindow::GlWindow(const std::string& name, unsigned int width, unsigned int height, Uint32 flags)
    : m_isWindowOpen(true)
{
    m_window = SDL_CreateWindow(name.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, width, height, flags);
    m_glContext = SDL_GL_CreateContext(m_window);
    m_sandbox = new Sandbox();
}

GlWindow::~GlWindow()
{
    delete m_sandbox;
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
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = (double) ((now - last) * 1000 / (double) SDL_GetPerformanceFrequency());
        while(SDL_PollEvent(&m_event) > 0)
        {
            switch(m_event.type)
            {
                case SDL_QUIT:
                    m_isWindowOpen = false;
                    break;
            }
        }
        m_sandbox->onUpdate(deltaTime);
        SDL_GL_SwapWindow(m_window);
    }
}