#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &rendererID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &rendererID);
}

void VertexArray::bind() const {
    glBindVertexArray(rendererID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}

void VertexArray::addVertexAttribPointer(unsigned int index, int size, GLenum type, bool normalized, int stride, const void* pointer) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized ? GL_TRUE : GL_FALSE, stride, pointer);
}
