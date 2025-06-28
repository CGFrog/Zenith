#include "Renderer.h"
#include <glad/glad.h>

void Renderer::submit(const std::shared_ptr<Renderable>& renderable) {
    renderQueue.push_back(renderable);
}

void Renderer::clearQueue() {
    renderQueue.clear();
}

void Renderer::render() {
    for (auto& renderable : renderQueue) {
        renderable->draw();
    }
    clearQueue();
}