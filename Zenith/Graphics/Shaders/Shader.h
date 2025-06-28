#pragma once
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void bind() const;
    void unbind() const;

    void setUniform(const std::string& name, int value);
    void setUniform(const std::string& name, float value);
    void setUniform(const std::string& name, const glm::vec3& value);
    void setUniform(const std::string& name, const glm::mat4& value);

private:
    unsigned int programID;

    std::string readFile(const std::string& path);
    unsigned int compileShader(unsigned int type, const std::string& source);
    int getUniformLocation(const std::string& name);

    std::unordered_map<std::string, int> uniformCache;
};
