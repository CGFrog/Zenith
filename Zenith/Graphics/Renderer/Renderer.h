#pragma once

#include <vector>
#include <memory>
#include "../Renderables/Renderable.h"
#include "../../Scene/Components/Transform.h"
#include "../Textures/Texture2D.h"

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    void submit(const std::shared_ptr<Renderable>& renderable);

    void clearQueue();

    void render(const glm::mat4& viewProj);

private:
    std::vector<std::shared_ptr<Renderable>> renderQueue;
};
