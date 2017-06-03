#include "logger.hpp"
#include "fpcamera.hpp"
#include "configscene.hpp"

void ConfigScene::build() {
  try {
    _shader.reset(new Core::Shader(
          Core::ShaderBuilder::createBuilder() 
          ->addSource(vertexPath)
          ->addSource(fragmentPath)
          ->build()));
  } catch (const std::string& error) {
    Logger::get().logLine(error);
  }
  _camera.reset(new Core::FPCamera(800, 600));
  _camera->setPosition(0.0f, 0.0f, 3.0f);

  try {
    _object.reset(
        new Core::WorldObject(
          std::make_shared<Core::Model>(modelPath)));
  } catch (const std::string& error) {
    Logger::get().logLine(error);
  }
  _object->_transform = glm::scale(_object->_transform, glm::vec3(0.2f, 0.2f, 0.2f));
}

void ConfigScene::draw() {
  _shader->use();

  _shader->uniformMatrix("model", _object->_transform);
  _shader->uniformMatrix("vpMatrix", _camera->vp_matrix());

  _object->_model->draw(*_shader);
}

void ConfigScene::setVertexShader(const std::string& path) {
  vertexPath = path;
}

void ConfigScene::setFragmentShader(const std::string& path) {
  fragmentPath = path;
}

void ConfigScene::setModel(const std::string& path) {
  modelPath = path;
}

