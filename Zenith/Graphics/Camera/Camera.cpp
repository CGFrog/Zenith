#include "Camera.h"
#include <algorithm>

Camera::Camera(float fovDegrees, float aspectRatio, float nearPlane, float farPlane)
    : fov(fovDegrees), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane),
    pitch(0.0f), yaw(-90.0f), up(0.0f, 1.0f, 0.0f), position(0.0f, 0.0f, 3.0f)
{
    updateDirection();
    updateProjection();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::getProjectionMatrix() const {
    return projectionMatrix;
}

void Camera::setPosition(const glm::vec3& pos) {
    position = pos;
}

glm::vec3 Camera::getPosition() const {
    return position;
}

void Camera::setRotation(float p, float y) {
    pitch = std::clamp(p, -89.0f, 89.0f);
    yaw = y;
    updateDirection();
}

void Camera::rotate(float yawDelta, float pitchDelta) {
    yaw += yawDelta;
    pitch = std::clamp(pitch + pitchDelta, -89.0f, 89.0f);
    updateDirection();
}

glm::vec3 Camera::getDirection() const {
    return front;
}

void Camera::move(const glm::vec3& delta) {
    position += delta;
}

void Camera::updateDirection() {
    glm::vec3 f;
    f.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    f.y = sin(glm::radians(pitch));
    f.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(f);
}

void Camera::updateProjection() {
    projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}
