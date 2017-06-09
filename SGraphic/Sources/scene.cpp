#include "camcontroller.hpp"
#include "scene.hpp"

Scene::Scene() { }

void Scene::attachController(std::shared_ptr<CamController> controller) {
  controller->setCamera(_camera); 
}

void Scene::resetShader(Core::Shader* newShader) {
  _shader.reset(newShader);
}
