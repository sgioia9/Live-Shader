#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <iostream>
#include "resourceloader.hpp"
#include "logger.hpp"
#include "model.hpp"

namespace Core {

  Model::Model(const std::string& path) {
    loadModel(path);
  }

  void Model::loadModel(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = 
      importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
      std::string error = "Assimp error: ";
      error += importer.GetErrorString();
      error += "\n";
      throw error;
    }

    // TODO: make it portable 
    _directory = path.substr(0, path.find_last_of('/'));
    processNode(scene->mRootNode, scene);;
  }

  void Model::processNode(aiNode* node, const aiScene* scene) {
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
        Logger::get().logLine("WARNING: No tex coords found");
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
      Logger::get().logLine("WARNING: No material found");
    } else {
      std::vector<Texture> diffuseMaps 
        = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
      textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

      std::vector<Texture> specularMaps
        = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
      textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }
    return Mesh(vertices, textures, indices);
  }

  void Model::draw(Shader& shader) {
    for (GLuint i = 0; i < _meshes.size(); ++i) {
      _meshes[i].draw(shader);
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
      if (loaded_textures.count(textureStr.C_Str()) > 0) {
        // Texture was already loaded for this model.
        textures.push_back(loaded_textures[textureStr.C_Str()]);
        continue;
      }
      // Texture hasn't been loaded. Do it.
      Texture texture;
      texture.id = ResourceLoader::get().generateTextureFromFile(_directory, textureStr.C_Str());
      texture.type = name;
      texture.path = textureStr;
      textures.push_back(texture);
      loaded_textures[textureStr.C_Str()] = texture; // mark it as loaded
    }
    return textures;
  }
}



