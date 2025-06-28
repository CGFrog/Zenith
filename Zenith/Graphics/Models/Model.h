#pragma once

#include <vector>
#include <memory>
#include "../Meshes/Mesh.h"
#include "../Renderables/Renderable.h"
#include "../../Scene/Components/Transform.h"

class Model : public Renderable {
public:
    Model() = default;

    void addMesh(std::shared_ptr<Mesh> mesh);

    void setTransform(const Transform& t) { transform = t; }
    const Transform& getTransform() const { return transform; }

    void draw(const glm::mat4& parentTransform = glm::mat4(1.0f)) override;

    const std::vector<std::shared_ptr<Mesh>>& getMeshes() const;

private:
    Transform transform;
    std::vector<std::shared_ptr<Mesh>> meshes;
};