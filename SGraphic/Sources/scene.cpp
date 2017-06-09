#include "camcontroller.hpp"
#include "scene.hpp"

Scene::Scene() { }

void Scene::resetShader(Core::Shader* newShader) {
  _shader.reset(newShader);
}
