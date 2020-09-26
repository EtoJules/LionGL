#pragma once

#include <GL/glew.h>
#include <string>
#include "glm/mat4x4.hpp"

#include "Helper/parser.h"

class Shader
{
private:
    unsigned int m_RenderID;
    std::string m_vertexSrc;
    std::string m_fragmentSrc;

public:
    Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~Shader();

public:
    void bind() const;
    void unbind() const;
    void setUniformMat4f(const std::string& name, glm::mat4 matrix);

private:
    unsigned int compileShader(unsigned int type, const std::string& source);
    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
    unsigned int getUniformLocation(std::string name) const;
};