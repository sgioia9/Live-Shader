#include <iostream>
#include <QKeyEvent>
#include "camerawidget.hpp"

CameraWidget::~CameraWidget() { }

void CameraWidget::initializeGL() {
  OglWidget::initializeGL();
  controller.reset(new NullCamController());
}

void CameraWidget::keyPressEvent(QKeyEvent* event) {
  controller->keyPressEvent(event);
}

void CameraWidget::mousePressEvent(QMouseEvent* event) {
  controller->mousePressEvent(event);
}
