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

void SceneWidget::initializeGL() {
  CameraWidget::initializeGL();

  _scene.reset(new NullScene());

  ConfigScene* scene = new ConfigScene();
  scene->setVertexShaderSource(VertexShaderEditor::get()->getText());
  scene->setFragmentShaderSource(FragmentShaderEditor::get()->getText());
  scene->setModel(
      "/home/stefano/Repositories/SGraphic/build/SGraphic/Resources/Models/nanosuit/nanosuit.obj");
  scene->build();

  attachScene(scene);
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

