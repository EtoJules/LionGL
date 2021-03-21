#pragma  once
#include "stb/stb_image.h"

#include "GL/glew.h"
#include <string>

class Texture
{
private:
    std::string m_filePath;
    uint m_RenderId;
    int m_width;
    int m_height;
    int m_channels;

public:
    Texture();
    explicit Texture(const std::string& filePath);
    ~Texture();
    std::string getFilePath() const;
    void loadTexture(const std::string& filePath);
    void bind(unsigned int slot = 0) const;
    static void unbind();
};