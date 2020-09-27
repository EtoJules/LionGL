#pragma  once
#include "stb/stb_image.h"

#include "GL/glew.h"
#include <string>

class Texture
{
private:
    unsigned int m_RenderId;
    int m_width;
    int m_height;
    int m_channels;

public:
    Texture();
    explicit Texture(const std::string& filePath);
    ~Texture();

public:
    void loadTexture(const std::string& filePath);
    void bind(unsigned int slot);
    void unbind();
};