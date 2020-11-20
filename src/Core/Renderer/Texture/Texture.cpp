#include "Texture.h"

Texture::Texture() {}

Texture::Texture(const std::string& filePath)
{
    loadTexture(filePath);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_RenderId);
}

void Texture::loadTexture(const std::string &filePath)
{
    unsigned char* image = stbi_load(filePath.c_str(), &m_width, &m_height, &m_channels, 0);

    glGenTextures(1, &m_RenderId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    if(image)
        stbi_image_free(image);
}

void Texture::bind(unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RenderId);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}