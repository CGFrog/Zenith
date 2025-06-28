#pragma once

#include <vector>
#include <memory>
#include "../Renderables/Renderable.h"

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    void submit(const std::shared_ptr<Renderable>& renderable);

    void clearQueue();

    void render();

private:
    std::vector<std::shared_ptr<Renderable>> renderQueue;
};
