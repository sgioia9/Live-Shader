#include <iostream>
#include <QKeyEvent>
#include "camerawidget.hpp"

void CameraWidget::initializeGL() {
  OglWidget::initializeGL();

  camera.reset(new Core::FPCamera(*this));
  camera->setPosition(0.0f, 0.0f, 3.0f);
  controller.setCamera(camera);
  controller.setWidget(std::shared_ptr<CameraWidget>(this));
}

void CameraWidget::keyPressEvent(QKeyEvent* event) {
  controller.keyPressEvent(event);
}

void CameraWidget::mousePressEvent(QMouseEvent* event) {
  controller.mousePressEvent(event);
}
