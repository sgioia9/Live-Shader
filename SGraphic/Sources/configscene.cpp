#include "logger.hpp"
#include <iostream>
#include "fpcamera.hpp"
#include "configscene.hpp"

ConfigScene::ConfigScene(const ModelInfo& info) {
  _vertexSource = info.vertexShaderSource;
  _fragmentSource = info.fragmentShaderSource;
  _modelPath = info.pathToModel;
  build();
}

ConfigScene::~ConfigScene() { }

void ConfigScene::build() {
  Logger::get().logLine("Building scene...");
  Logger::get().logLine("Compiling shaders...");
  buildShader(_vertexSource, _fragmentSource);
  Logger::get().logLine("Shader program compiled & linked");
  _camera.reset(new Core::FPCamera(800, 600));
  _camera->setPosition(0.0f, 0.0f, 3.0f);

  Logger::get().logLine("Loading model: " + _modelPath);
  _object.reset(
      new Core::WorldObject(
        std::make_shared<Core::Model>(_modelPath)));
  _object->_transform = glm::scale(_object->_transform, glm::vec3(0.2f, 0.2f, 0.2f));
  Logger::get().logLine("Model loaded");
  Logger::get().logLine("Scene loaded");
}

void ConfigScene::draw() {
  _shader->use();

  _shader->uniformMatrix("model", _object->_transform);
  _shader->uniformMatrix("vpMatrix", _camera->vp_matrix());

  _object->_model->draw(*_shader);
}

void ConfigScene::buildShader(
    const std::string& vertexSource,
    const std::string& fragmentSource) {
  _vertexSource = vertexSource;
  _fragmentSource = fragmentSource;
  _shader.reset(new Core::Shader(
        Core::ShaderBuilder::createBuilder() 
        ->addVertexShaderSource(_vertexSource)
        ->addFragmentShaderSource(_fragmentSource)
        ->build()));
}
