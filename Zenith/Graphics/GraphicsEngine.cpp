#include "GraphicsEngine.h"
#include <iostream>

bool GraphicsEngine::initialize(int width, int height, const char* title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return false;
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    return true;
}

void GraphicsEngine::shutdown() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool GraphicsEngine::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void GraphicsEngine::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsEngine::swapBuffers() const {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GraphicsEngine::run() {
    while (!shouldClose()) {
        clear();
        swapBuffers();
    }
}

GLFWwindow* GraphicsEngine::getWindow() const {
    return window;
}

Renderer& GraphicsEngine::getRenderer() {
    return renderer;
}

