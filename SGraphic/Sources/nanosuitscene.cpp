#include "scene.hpp"

#include "shader.hpp"
#include "worldobject.hpp"
#include "fpcamera.hpp"
#include "camcontroller.hpp"
#include "nanosuitscene.hpp"

NanosuitScene::NanosuitScene() {
  _shader.reset(new Core::Shader(
        Core::ShaderBuilder::createBuilder() 
        ->addSource("simple.vert")
        ->addSource("simple.frag")
        ->build()));
  _camera.reset(new Core::FPCamera(800, 600));
  _camera->setPosition(0.0f, 0.0f, 3.0f);
  _object.reset(
      new Core::WorldObject(
        std::make_shared<Core::Model>("nanosuit/nanosuit.obj")));

  _object->_transform = glm::scale(_object->_transform, glm::vec3(0.2f, 0.2f, 0.2f));
}

void NanosuitScene::draw() {
  _shader->use();

  _shader->uniformMatrix("model", _object->_transform);
  _shader->uniformMatrix("vpMatrix", _camera->vp_matrix());

  _object->_model->draw(*_shader);
}


