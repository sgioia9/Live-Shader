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
#include "nanosuitscene.hpp"
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

  /*
  shader->uniformMatrix("model", object->_transform);
  shader->uniformMatrix("vpMatrix", camera->vp_matrix());

  object->_model->draw(*shader);
  */
}

QSize TestWidget::sizeHint() const {
  return QSize(800, 600);
}

void TestWidget::onEvent(GuiReadyEvent& event) {
  std::cerr << "GUI Ready" << std::endl;
  _scene.reset(new NanosuitScene());
  _scene->attachController(controller);
}

TestWidget::~TestWidget() {
  guiReadyRegistration->removeHandler();
  delete guiReadyRegistration;
}

