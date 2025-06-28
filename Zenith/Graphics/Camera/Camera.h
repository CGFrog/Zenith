#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

class Camera {
public:
    Camera(float fovDegrees, float aspectRatio, float nearPlane, float farPlane);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;

    void setPosition(const glm::vec3& pos);
    glm::vec3 getPosition() const;

    void setRotation(float pitch, float yaw);
    void rotate(float yawDelta, float pitchDelta);

    glm::vec3 getDirection() const;

    void move(const glm::vec3& delta);

private:
    void updateDirection();
    void updateProjection();

    float fov, aspectRatio, nearPlane, farPlane;
    float pitch, yaw;
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::mat4 projectionMatrix;
};
