#pragma once
#include <glad/glad.h>

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void bind() const;
    void unbind() const;

    void addVertexAttribPointer(unsigned int index, int size, GLenum type, bool normalized, int stride, const void* pointer);

private:
    unsigned int rendererID;
};
