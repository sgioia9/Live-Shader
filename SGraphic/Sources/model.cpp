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
}



