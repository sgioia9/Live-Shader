#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "mesh.hpp"
#include <assimp/scene.h>

namespace Core {
class Model {
public:
  Model(const std::string& path) {
    loadModel(path);
  }
private:
  static const std::string MODEL_DIR;

  std::unordered_map<std::string, Texture> loaded_textures; // path -> Texture 
  std::vector<Mesh> _meshes;

  void loadModel(const std::string& path);
  void processNode(aiNode* node, const aiScene* scene);
  Mesh processMesh(aiMesh* mesh, const aiScene* scene);

  std::vector<Texture> loadMaterialTextures(
      aiMaterial* mat, 
      aiTextureType type, 
      const std::string& name);
};
}

#endif
