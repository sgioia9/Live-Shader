#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "testwidget.hpp"
#include "resourceloader.hpp"
#include "mainframe.hpp"
#include "EventBus.hpp"
#include "scene.hpp"
#include "configscene.hpp"
#include "logger.hpp"

void TestWidget::initializeGL() {
  CameraWidget::initializeGL();
  guiReadyRegistration = EventBus::AddHandler<GuiReadyEvent>(*this);
  _scene.reset(new NullScene());
}

void TestWidget::teardownGL() { }

void TestWidget::paintGL() {
  CameraWidget::paintGL();
  _scene->draw();
}

QSize TestWidget::sizeHint() const {
  return QSize(800, 600);
}

void TestWidget::attachScene(Scene* scene) {
  _scene.reset(scene);
  _scene->attachController(controller);
}

void TestWidget::onEvent(GuiReadyEvent& event) {
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

TestWidget::~TestWidget() {
  guiReadyRegistration->removeHandler();
  delete guiReadyRegistration;
}

