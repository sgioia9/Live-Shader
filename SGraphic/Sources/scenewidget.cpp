#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "scenewidget.hpp"
#include "resourceloader.hpp"
#include "mainframe.hpp"
#include "EventBus.hpp"
#include "scene.hpp"
#include "configscene.hpp"
#include "logger.hpp"

void SceneWidget::initializeGL() {
  CameraWidget::initializeGL();
  guiReadyRegistration = EventBus::AddHandler<GuiReadyEvent>(*this);
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
  _scene->attachController(controller);
}

void SceneWidget::onEvent(GuiReadyEvent& event) {
  (void)event;
  std::cerr << "GUI Ready" << std::endl;
  // TODO: ac'a en realidad no se deber'ia cargar nada. Se deber'ia hacer desde la gui.
  ConfigScene* scene = new ConfigScene();
  scene->setVertexShader("/home/stefano/Repositories/SGraphic/SGraphic/Shaders/simple.vert");
  scene->setFragmentShader("/home/stefano/Repositories/SGraphic/SGraphic/Shaders/simple.frag");
  scene->setModel("/home/stefano/Repositories/SGraphic/SGraphic/Models/nanosuit/nanosuit.obj");
  scene->build();
  attachScene(scene);
}

SceneWidget::~SceneWidget() {
  guiReadyRegistration->removeHandler();
  delete guiReadyRegistration;
}

