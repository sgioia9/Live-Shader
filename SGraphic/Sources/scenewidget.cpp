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
  ModelInfo auxInfo = Configuration::get().getModelInfo();
  auxInfo.pathToModel =
    "/home/stefano/Repositories/SGraphic/build/SGraphic/Resources/Models/nanosuit/nanosuit.obj";
  _scene.reset(new ConfigScene(auxInfo));
}

void SceneWidget::paintGL() {
  CameraWidget::paintGL();
  _scene->draw();
}

QSize SceneWidget::sizeHint() const {
  return QSize(800, 600);
}

void SceneWidget::onNewConfig(const ModelInfo& info) {
  std::cerr << "reinitialize" << std::endl;
  initializeGL();
  controller.reset(new CamController());
  _scene->attachController(controller);
}
