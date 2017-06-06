#include "mesh.hpp"

#include <cstddef>
#include <sstream>
#include <string>
#include <iostream>
#include "scenewidget.hpp"

namespace Core {
  Mesh::Mesh(const Vertices& vertices,
             const Textures& textures,
             const Indices& indices) 
    : _vertices(vertices),
      _textures(textures),
      _indices(indices) { 
    gl = SceneWidget::get();
    gl->glGenVertexArrays(1, &_VAO); 
    gl->glGenBuffers(1, &_EBO);
    gl->glGenBuffers(1, &_VBO);
    /*
    std::cerr << "creating vao " << _VAO << std::endl;
    std::cerr << "creating ebo " << _EBO << std::endl;
    std::cerr << "creating vbo " << _VBO << std::endl;
    std::cerr << "indices size " << _indices.size() << std::endl;
    */

    gl->glBindVertexArray(_VAO);
      gl->glBindBuffer(GL_ARRAY_BUFFER, _VBO);
      gl->glBufferData(
          GL_ARRAY_BUFFER, 
          _vertices.size() * sizeof(Vertex),
          &_vertices[0],
          GL_STATIC_DRAW);

      gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
      gl->glBufferData(
          GL_ELEMENT_ARRAY_BUFFER,
          _indices.size() * sizeof(GLuint),
          &_indices[0],
          GL_STATIC_DRAW);

      // vertex pos 
      gl->glEnableVertexAttribArray(0);
      gl->glVertexAttribPointer(
          0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

      // vertex normals
      gl->glEnableVertexAttribArray(1);
      gl->glVertexAttribPointer(
          1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

      // vertex tex coords
      gl->glEnableVertexAttribArray(2);
      gl->glVertexAttribPointer(
          2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords)); 

      gl->glBindBuffer(GL_ARRAY_BUFFER, 0);
    gl->glBindVertexArray(0);
  }

  void Mesh::draw(Shader& shader) {
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    for (GLuint i = 0; i < _textures.size(); ++i) {
      gl->glActiveTexture(GL_TEXTURE0 + i);
      std::stringstream ss;
      std::string number;
      std::string name = _textures[i].type;
      if (name == "texture_diffuse")
        ss << diffuseNr++;
      else if (name == "texture_specular")
        ss << specularNr++;
      number = ss.str();

      shader.uniformInt(name + number, i); // set sampler to texture unit
      gl->glBindTexture(GL_TEXTURE_2D, _textures[i].id);
    }
    shader.uniformFloat("shininess", 16.0f);

    gl->glBindVertexArray(_VAO);
    gl->glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    gl->glBindVertexArray(0);

    for (GLuint i = 0; i < _textures.size(); ++i) {
      gl->glActiveTexture(GL_TEXTURE0 + i);
      // unbind textures from texture units
      gl->glBindTexture(GL_TEXTURE_2D, 0);
    }
  }

}
