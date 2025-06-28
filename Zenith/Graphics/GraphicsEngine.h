#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer/Renderer.h"

class GraphicsEngine {
public:
    bool initialize(int width, int height, const char* title);
    void shutdown();

    bool shouldClose() const;
    void clear() const;
    void swapBuffers() const;

    void run();

    GLFWwindow* getWindow() const;

    Renderer& getRenderer();

private:
    GLFWwindow* window = nullptr;

    Renderer renderer;
};
