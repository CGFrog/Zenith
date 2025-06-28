#pragma once
#include <glm/glm.hpp>


class Renderable {
public:
    virtual ~Renderable() = default;
    virtual void draw(const glm::mat4& viewProj) = 0;
};
