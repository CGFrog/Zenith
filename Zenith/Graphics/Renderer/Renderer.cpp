#include "Renderer.h"
#include <glad/glad.h>

void Renderer::submit(const std::shared_ptr<Renderable>& renderable) {
    renderQueue.push_back(renderable);
}

void Renderer::clearQueue() {
    renderQueue.clear();
}

void Renderer::render(const glm::mat4& viewProj) {
    for (auto& renderable : renderQueue) {
        renderable->draw(viewProj);
    }
    clearQueue();
}