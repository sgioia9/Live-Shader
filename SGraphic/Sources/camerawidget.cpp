#include <iostream>
#include <QKeyEvent>
#include "camerawidget.hpp"

void CameraWidget::initializeGL() {
  OglWidget::initializeGL();
}

void CameraWidget::keyPressEvent(QKeyEvent* event) {
  controller.keyPressEvent(event);
}

void CameraWidget::mousePressEvent(QMouseEvent* event) {
  controller.mousePressEvent(event);
}
