#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class InputHandler {
public:
    explicit InputHandler(GLFWwindow* window);

    void update();

    bool isMovingForward() const;
    bool isMovingBackward() const;
    bool isMovingLeft() const;
    bool isMovingRight() const;

    glm::vec2 getMouseDelta() const;

    void resetMouseDelta();

private:
    GLFWwindow* window;

    glm::vec2 mouseDelta;
    double lastX, lastY = 0;
    bool firstMouse;

    static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

    static InputHandler* instance;
};
