#include "Texture2D.h"
#include "../../External/stb/stb_img.h"
#include <iostream>

Texture2D::Texture2D(const std::string& filePath, bool flipVertically) {
    stbi_set_flip_vertically_on_load(flipVertically);

    unsigned char* data = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_Channels, 0);
    if (!data) {
        std::cerr << "Failed to load texture: " << filePath << std::endl;
        m_ID = 0;
        return;
    }

    GLenum format = GL_RGB;
    if (m_Channels == 1) format = GL_RED;
    else if (m_Channels == 3) format = GL_RGB;
    else if (m_Channels == 4) format = GL_RGBA;

    glGenTextures(1, &m_ID);
    glBindTexture(GL_TEXTURE_2D, m_ID);

    // Upload texture to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Texture settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &m_ID);
}

void Texture2D::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture2D::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
