#include "mesh.hpp"

#include <cstddef>
#include <sstream>
#include <string>

namespace Core {
  Mesh::Mesh(const Vertices& vertices,
             const Textures& textures,
             const Indices& indices) 
    : _vertices(vertices),
      _textures(textures),
      _indices(indices) { 
    initializeOpenGLFunctions();
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

  void Mesh::draw(const Shader& shader) {
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    for (GLuint i = 0; i < _textures.size(); ++i) {
      glActiveTexture(GL_TEXTURE0 + i);
      std::stringstream ss;
      std::string number;
      std::string name = _textures[i].type;
      if (name == "texture_diffuse")
        ss << diffuseNr++;
      else if (name == "texture_specular")
        ss << specularNr++;
      number = ss.str();
    }
  }

}
