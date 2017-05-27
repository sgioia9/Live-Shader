#ifndef MESH_HPP
#define MESH_HPP

#include <glm/glm.hpp>

#include <assimp/scene.h>

#include <string>
#include <vector>

#include "shader.hpp"
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>

namespace Core {
struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 texCoords;
};

struct Texture{
  GLuint id;
  std::string type;
  aiString path; // to compare with other textures
};

class Mesh : QOpenGLExtraFunctions {
  using Vertices = std::vector<Vertex>;
  using Textures = std::vector<Texture>;
  using Indices = std::vector<GLuint>;

public:
  Mesh(const Vertices& vertices,
       const Textures& textures,
       const Indices& indices);

  void draw(Shader& shader);
  const Vertices _vertices;
  const Textures _textures;
  const Indices _indices;
private:
  GLuint _VAO, _VBO, _EBO;
};
}

#endif // MESH_HPP

