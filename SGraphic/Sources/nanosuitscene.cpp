#include "scene.hpp"

#include "shader.hpp"
#include "worldobject.hpp"
#include "fpcamera.hpp"
#include "camcontroller.hpp"
#include <iostream>
#include "logger.hpp"
#include "nanosuitscene.hpp"

NanosuitScene::NanosuitScene() {
  try {
    _shader.reset(new Core::Shader(
          Core::ShaderBuilder::createBuilder() 
          ->addSource("/home/stefano/Repositories/SGraphic/SGraphic/Shaders/simple.vert")
          ->addSource("/home/stefano/Repositories/SGraphic/SGraphic/Shaders/simple.frag")
          ->build()));
  } catch (const std::string& error) {
    Logger::get().logLine(error);
  }
  _camera.reset(new Core::FPCamera(800, 600));
  _camera->setPosition(0.0f, 0.0f, 3.0f);
  try {
  _object.reset(
      new Core::WorldObject(
        std::make_shared<Core::Model>("nanosuit/nanosuit.obj")));
  } catch (const std::string& error) {
    Logger::get().logLine(error);
  }
  _object->_transform = glm::scale(_object->_transform, glm::vec3(0.2f, 0.2f, 0.2f));
}

void NanosuitScene::draw() {
  _shader->use();

  _shader->uniformMatrix("model", _object->_transform);
  _shader->uniformMatrix("vpMatrix", _camera->vp_matrix());

  _object->_model->draw(*_shader);
}

