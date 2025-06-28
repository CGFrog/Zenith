#pragma once
#include "../Shaders/Shader.h"
#include <memory>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <unordered_map>
#include <string>

class Material {
public:
    explicit Material(std::shared_ptr<Shader> shader);

    void bind() const;
    void unbind() const;

    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
    void setVec3(const std::string& name, const glm::vec3& value);
    void setMat4(const std::string& name, const glm::mat4& value);

private:
    std::shared_ptr<Shader> shader;
};
