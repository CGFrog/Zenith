#include "Transform.h"


Transform::Transform()
    : position(0.0f), rotation(0.0f), scale(1.0f) {}

void Transform::setPosition(const glm::vec3& pos) {
    position = pos;
}

void Transform::setRotation(const glm::vec3& rot) {
    rotation = rot;
}

void Transform::setScale(const glm::vec3& scl) {
    scale = scl;
}

glm::vec3 Transform::getPosition() const {
    return position;
}

glm::vec3 Transform::getRotation() const {
    return rotation;
}

glm::vec3 Transform::getScale() const {
    return scale;
}

glm::mat4 Transform::getModelMatrix() const {
    glm::mat4 T = glm::translate(glm::mat4(1.0f), position);
    glm::mat4 R = glm::eulerAngleYXZ(rotation.y, rotation.x, rotation.z);
    glm::mat4 S = glm::scale(glm::mat4(1.0f), scale);
    return T * R * S;
}
