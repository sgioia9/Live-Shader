#include "camcontroller.hpp"
#include "scene.hpp"

Scene::Scene() { }

void Scene::attachController(CamController& controller) {
  controller.setCamera(_camera); 
}

