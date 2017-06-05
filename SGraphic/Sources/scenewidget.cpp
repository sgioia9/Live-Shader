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
#include "logger.hpp"

void SceneWidget::initializeGL() {
  CameraWidget::initializeGL();
  _scene.reset(new NullScene());
}

void SceneWidget::teardownGL() { }

void SceneWidget::paintGL() {
  CameraWidget::paintGL();
  _scene->draw();
}

QSize SceneWidget::sizeHint() const {
  return QSize(800, 600);
}

void SceneWidget::attachScene(Scene* scene) {
  _scene.reset(scene);
  controller.reset(new CamController());
  _scene->attachController(controller);
}

