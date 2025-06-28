#include "Model.h"

void Model::addMesh(std::shared_ptr<Mesh> mesh) {
    meshes.push_back(mesh);
}

void Model::draw(const glm::mat4& parentTransform) {
    glm::mat4 modelMatrix = parentTransform * transform.getModelMatrix();

    for (const auto& mesh : meshes) {
        mesh->draw(modelMatrix);
    }
}

const std::vector<std::shared_ptr<Mesh>>& Model::getMeshes() const {
    return meshes;
}