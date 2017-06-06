#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "scenewidget.hpp"
#include "resourceloader.hpp"
#include "mainframe.hpp"
#include "scene.hpp"
#include "configscene.hpp"
#include "vertexshadereditor.hpp"
#include "fragmentshadereditor.hpp"
#include "logger.hpp"
#include "configuration.hpp"

SceneWidget* SceneWidget::instance = nullptr;

SceneWidget* SceneWidget::get() {
  if (!instance) instance = new SceneWidget();
  return instance;
}

SceneWidget::SceneWidget() { }
SceneWidget::~SceneWidget() { std::cerr << "scene widget destroyed" << std::endl; }

void SceneWidget::initializeGL() {
  CameraWidget::initializeGL();
  _scene.reset(new NullScene());
}

void SceneWidget::paintGL() {
  CameraWidget::paintGL();
  _scene->draw();
  if (!newModelEvents.empty()) {
    const ModelInfo event = newModelEvents.front();
    newModelEvents.pop();
    _scene.reset(new ConfigScene(event));
  }
}

QSize SceneWidget::sizeHint() const {
  return QSize(800, 600);
}

void SceneWidget::onNewConfig(const ModelInfo& info) {
  std::cerr << "reinitialize" << std::endl;
  std::cerr << "queue sending\n" << info.vertexShaderSource << std::endl;
  newModelEvents.push(info);
}
