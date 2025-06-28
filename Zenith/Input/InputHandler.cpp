#include "InputHandler.h"

InputHandler* InputHandler::instance = nullptr;

InputHandler::InputHandler(GLFWwindow* win)
    : window(win), mouseDelta(0.f), firstMouse(true)
{
    instance = this;
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
}

void InputHandler::update() {
    // Add key buffering here if needed
}

bool InputHandler::isMovingForward() const {
    return glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
}

bool InputHandler::isMovingBackward() const {
    return glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
}

bool InputHandler::isMovingLeft() const {
    return glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
}

bool InputHandler::isMovingRight() const {
    return glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
}

glm::vec2 InputHandler::getMouseDelta() const {
    return mouseDelta;
}

void InputHandler::resetMouseDelta() {
    mouseDelta = glm::vec2(0.f);
}

void InputHandler::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (!instance)
        return;

    if (instance->firstMouse) {
        instance->lastX = xpos;
        instance->lastY = ypos;
        instance->firstMouse = false;
    }

    double xoffset = xpos - instance->lastX;
    double yoffset = instance->lastY - ypos;

    instance->lastX = xpos;
    instance->lastY = ypos;

    instance->mouseDelta += glm::vec2(static_cast<float>(xoffset), static_cast<float>(yoffset));
}
