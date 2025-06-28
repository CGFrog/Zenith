#pragma once
#include <string>
#include <glad/glad.h>

class Texture2D {
public:
    Texture2D(const std::string& filePath, bool flipVertically = true);
    ~Texture2D();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    int getWidth() const { return m_Width; }
    int getHeight() const { return m_Height; }
    GLuint getID() const { return m_ID; }

private:
    GLuint m_ID;
    int m_Width;
    int m_Height;
    int m_Channels;
};
