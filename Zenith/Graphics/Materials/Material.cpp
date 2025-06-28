#include "Material.h"

Material::Material(std::shared_ptr<Shader> shader)
    : shader(std::move(shader))
{}

void Material::bind() const {
    shader->bind();
}

void Material::unbind() const {
    shader->unbind();
}

std::shared_ptr<Shader> Material::getShader() {
    return shader;
}

void Material::setInt(const std::string& name, int value) {
    shader->setUniform(name, value);
}

void Material::setFloat(const std::string& name, float value) {
    shader->setUniform(name, value);
}

void Material::setVec3(const std::string& name, const glm::vec3& value) {
    shader->setUniform(name, value);
}

void Material::setMat4(const std::string& name, const glm::mat4& value) {
    shader->setUniform(name, value);
}
