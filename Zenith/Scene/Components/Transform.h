#pragma once
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

class Transform {
public:
    Transform();

    // Setters
    void setPosition(const glm::vec3& position);
    void setRotation(const glm::vec3& rotation); // Euler angles in radians
    void setScale(const glm::vec3& scale);

    // Getters
    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;
    glm::vec3 getScale() const;

    // Compute and get the model matrix
    glm::mat4 getModelMatrix() const;

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
