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

struct Texture {
  GLuint id;
  std::string type;
  aiString path; // to compare with other textures

  bool operator==(const Texture& other) const {
    return path != other.path;
  }

  friend std::ostream& operator<<(std::ostream& out, const Texture& tex) {
    return out << "Texture: ID = " << tex.id 
      << ", type = " << tex.type 
      << ", path = " << tex.path.C_Str() 
      << std::endl;
  }
};

class Mesh : QOpenGLExtraFunctions {
  using Vertices = std::vector<Vertex>;
  using Textures = std::vector<Texture>;
  using Indices = std::vector<GLuint>;

public:
  // TODO: add dtor
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

namespace std {
  template<>
  struct hash<Core::Texture> {
    std::size_t operator()(const Core::Texture& t) const {
      return hash<string>()(t.path.C_Str());
    }
  };
}

#endif // MESH_HPP

