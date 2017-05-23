#include "mesh.hpp"

#include <cstddef>

namespace Core {
  Mesh::Mesh(const Vertices& vertices,
             const Textures& textures,
             const Indices& indices) 
    : _vertices(vertices),
      _textures(textures),
      _indices(indices) { 
    glGenVertexArrays(1, &_VAO); 
    glGenBuffers(1, &_VBO);
    glGenBuffers(1, &_EBO);

    glBindVertexArray(_VAO);
      glBindBuffer(GL_ARRAY_BUFFER, _VBO);
      glBufferData(
          GL_ARRAY_BUFFER, 
          _vertices.size() * sizeof(Vertex),
          &_vertices[0],
          GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
      glBufferData(
          GL_ELEMENT_ARRAY_BUFFER,
          _indices.size() * sizeof(GLuint),
          &_indices[0],
          GL_STATIC_DRAW);

      // vertex pos 
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(
          0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

      // vertex normals
      glEnableVertexAttribArray(1);
      glVertexAttribPointer(
          1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normals));

      // vertex tex coords
      glEnableVertexAttribArray(2);
      glVertexAttribPointer(
          2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords)); 
    glBindVertexArray(0);
  }

  void Mesh::draw(const Shader& shader) const {

  }

}
