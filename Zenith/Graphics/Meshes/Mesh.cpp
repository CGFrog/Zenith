#include "Mesh.h"

Mesh::Mesh(std::shared_ptr<VertexArray> vao,
    std::shared_ptr<VertexBuffer> vbo,
    std::shared_ptr<IndexBuffer> ibo,
    std::shared_ptr<Material> material)
    : vertexArray(std::move(vao)),
    vertexBuffer(std::move(vbo)),
    indexBuffer(std::move(ibo)),
    material(std::move(material))
{}

void Mesh::draw(const glm::mat4& viewProj) {
    material->bind();
    material->setMat4("u_ViewProjection", viewProj);
    vertexArray->bind();
    indexBuffer->bind();

    glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);

    indexBuffer->unbind();
    vertexArray->unbind();
    material->unbind();
}
