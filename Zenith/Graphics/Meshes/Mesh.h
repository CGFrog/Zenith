#pragma once
#include "../Buffers/VertexArray.h"
#include "../Buffers/VertexBuffer.h"
#include "../Buffers/IndexBuffer.h"
#include "../Materials/Material.h"
#include <memory>
#include "../Renderables/Renderable.h"
#include "../../Scene/Components/Transform.h"

class Mesh : public Renderable{
public:
    Mesh(std::shared_ptr<VertexArray> vao,
        std::shared_ptr<VertexBuffer> vbo,
        std::shared_ptr<IndexBuffer> ibo,
        std::shared_ptr<Material> material);

    void draw(const glm::mat4& parentTransform = glm::mat4(1.0f)) override;
    void setTransform(const Transform& transform) { this->transform = transform; }
    const Transform& getTransform() const { return transform; }

    std::shared_ptr<Material> getMaterial() const { return material; }

private:
    Transform transform;
    std::shared_ptr<VertexArray> vertexArray;
    std::shared_ptr<VertexBuffer> vertexBuffer;
    std::shared_ptr<IndexBuffer> indexBuffer;
    std::shared_ptr<Material> material;
};
