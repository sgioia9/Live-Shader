#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <iostream>
#include "model.hpp"

namespace Core {
#ifdef DEVELOP
  const std::string Model::MODEL_DIR 
    = "/home/stefano/Repositories/SGraphic/SGraphic/Models/";
#else
  const std::string Model::MODEL_DIR = "";
#endif

  void Model::loadModel(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = 
      importer.ReadFile(MODEL_DIR + path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
      std::cerr << "Assimp error: " << importer.GetErrorString() << std::endl;
    }
    processNode(scene->mRootNode, scene);;
  }

  void Model::processNode(aiNode* node, const aiScene* scene) {
    // TODO: acá se pueden distinguri las relaciones de padre-hijo
    // de los meshes. Hacerlo!
    for (GLuint i = 0; i < node->mNumMeshes; ++i) {
      aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
      _meshes.push_back(processMesh(mesh, scene));
    }
    for (GLuint i = 0; i < node->mNumChildren; ++i) {
      processNode(node->mChildren[i], scene);
    }
  }

  Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
    std::vector<Vertex> vertices;
    std::vector<Texture> textures;
    std::vector<GLuint> indices;

    // fill in Vertex structs
    for (GLuint i = 0; i < mesh->mNumVertices; ++i) {
      Vertex vertex;

      glm::vec3 position;
      position.x = mesh->mVertices[i].x;
      position.y = mesh->mVertices[i].y;
      position.z = mesh->mVertices[i].z;
      vertex.position = position;

      glm::vec3 normal;
      normal.x = mesh->mNormals[i].x;
      normal.y = mesh->mNormals[i].y;
      normal.z = mesh->mNormals[i].z;
      vertex.normal = normal;

      // assimp allows 8 tex coords. we only use the first
      if (mesh->mTextureCoords[0]) {
        glm::vec2 texCoords;
        texCoords.x = mesh->mTextureCoords[0][i].x;
        texCoords.y = mesh->mTextureCoords[0][i].y;
        vertex.texCoords = texCoords;
      } else {
        std::cerr << "WARNING: No tex coords found\n";
        vertex.texCoords = glm::vec2(0.0f, 0.0f);
      }

      vertices.push_back(vertex);;
    }

    // fill in Texture structs
    for (GLuint i = 0; i < mesh->mNumFaces; ++i) {
      const aiFace& face = mesh->mFaces[i];
      for (GLuint j = 0; j < face.mNumIndices; j++) {
        indices.push_back(face.mIndices[j]);
      }
    }

    // retrieve material
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
    if (!material) {
      std::cerr << "WARNING: No material found\n";
    } else {
      std::vector<Texture> diffuseMaps 
        = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
      textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

      std::vector<Texture> specularMaps
        = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
      textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }
  }

  std::vector<Texture> Model::loadMaterialTextures(
      aiMaterial* material,
      aiTextureType type,
      const std::string& name) {
    std::vector<Texture> textures;
    for (GLuint i = 0; i < material->GetTextureCount(type); ++i) {
      aiString textureStr;
      material->GetTexture(type, i, &textureStr);
      Texture texture;
      texture.type = name;
      texture.path = textureStr;
      textures.push_back(texture);
    }
    return textures;
  }
}



