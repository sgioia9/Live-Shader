#include "logger.hpp"
#include <iostream>
#include "fpcamera.hpp"
#include "configscene.hpp"

ConfigScene::ConfigScene(const ModelInfo& info) {
  std::cerr << "config scene receives\n" << info.vertexShaderSource << std::endl;
  _vertexSource = info.vertexShaderSource;
  _fragmentSource = info.fragmentShaderSource;
  _modelPath = info.pathToModel;
  build();
}

ConfigScene::~ConfigScene() {
  std::cerr << "config scene destroyed" << std::endl;
}

void ConfigScene::build() {
  std::cerr << "building scene" << std::endl;
  try {
    _shader.reset(new Core::Shader(
          Core::ShaderBuilder::createBuilder() 
          ->addVertexShaderSource(_vertexSource)
          ->addFragmentShaderSource(_fragmentSource)
          ->build()));
  } catch (const std::string& error) {
    std::cerr << "shader error " << error << std::endl;
  }
  std::cerr << " shaders built "  << std::endl;
  _camera.reset(new Core::FPCamera(800, 600));
  _camera->setPosition(0.0f, 0.0f, 3.0f);

  try {
    _object.reset(
        new Core::WorldObject(
          std::make_shared<Core::Model>(_modelPath)));
  } catch (const std::string& error) {
    std::cerr << "model error" << error << std::endl;
  }
  _object->_transform = glm::scale(_object->_transform, glm::vec3(0.2f, 0.2f, 0.2f));
  std::cerr << "model loaded & transformed " << std::endl;
}

void ConfigScene::draw() {
  _shader->use();

  _shader->uniformMatrix("model", _object->_transform);
  _shader->uniformMatrix("vpMatrix", _camera->vp_matrix());

  _object->_model->draw(*_shader);
}
