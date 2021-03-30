#include "Texture.h"

oglite::Texture::Texture() : m_filePath("") {}

oglite::Texture::Texture(const std::string& filePath) : m_filePath(filePath){
    loadTexture(filePath);
}

oglite::Texture::~Texture(){
    glDeleteTextures(1, &m_RenderId);
}

void oglite::Texture::loadTexture(const std::string &filePath){
    unsigned char* image = stbi_load(filePath.c_str(), &m_width, &m_height, &m_channels, 0);
    m_filePath = filePath;

    glGenTextures(1, &m_RenderId);
    bind(m_RenderId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    unbind();

    if(image)
        stbi_image_free(image);
}

void oglite::Texture::bind(unsigned int slot) const{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RenderId);
}

void oglite::Texture::unbind(){
    glBindTexture(GL_TEXTURE_2D, 0);
}

std::string oglite::Texture::getFilePath() const{
    return m_filePath;
}
