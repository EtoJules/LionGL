#pragma once

#include <GL/glew.h>
#include "Shader/Shader.h"
#include "VertexBuffer/VertexBuffer.h"

class Renderer
{
private:
    unsigned int m_RenderId;

public:
    void draw();
    void clear();
};