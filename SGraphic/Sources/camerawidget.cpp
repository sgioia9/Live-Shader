#include <iostream>
#include <QKeyEvent>
#include "camerawidget.hpp"

CameraWidget::~CameraWidget() { }

void CameraWidget::initializeGL() {
  OglWidget::initializeGL();
  _camController.reset(new NullCamController());
}

void CameraWidget::keyPressEvent(QKeyEvent* event) {
  _camController->keyPressEvent(event);
}

void CameraWidget::mousePressEvent(QMouseEvent* event) {
  _camController->mousePressEvent(event);
}

void CameraWidget::wheelEvent(QWheelEvent* event) {
  _camController->wheelEvent(event);
}
