#include "fpcamera.hpp"
#include <memory>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <iostream>
#include "camerawidget.hpp"

#include "camcontroller.hpp"

CamController::CamController() { }

CamController::CamController(
    const std::shared_ptr<Core::FPCamera>& cam, CameraWidget* widget)
  : _camera(cam), _widget(widget) { }
       
void CamController::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_A:
      _camera->moveLeft();
      break;
    case Qt::Key_S:
      _camera->moveBackward();
      break;
    case Qt::Key_D:
      _camera->moveRight();
      break;
    case Qt::Key_W:
      _camera->moveForward();
      break;
    case Qt::Key_Up:
      _camera->moveUp();
      break;
    case Qt::Key_Down:
      _camera->moveDown();
      break;
    case Qt::Key_Left:
      _camera->lookLeft();
      break;
    case Qt::Key_Right:
      _camera->lookRight();
      break;
    case Qt::Key_Plus:
      _camera->lookUp();
      break;
    case Qt::Key_Minus:
      _camera->lookDown();
      break;
    case Qt::Key_Escape:
      _widget->clearFocus();
      break;
  }
  // std::cerr << *_camera << std::endl;
}

void CamController::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    std::cerr << "mouse clicked" << std::endl;
  }
}

void CamController::wheelEvent(QWheelEvent* event) {
  if (event->delta() > 0) {
    _camera->moveForward();
  } else if (event->delta() < 0) {
    _camera->moveBackward();
  }
}
