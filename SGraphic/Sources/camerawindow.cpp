#include <iostream>
#include <QKeyEvent>
#include "camerawindow.hpp"

void CameraWindow::initializeGL() {
  OglWindow::initializeGL();
  camera.reset(new Core::FPCamera(*this));
  camera->setPosition(0.0f, 0.0f, 3.0f);
}

void CameraWindow::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_A) {
    camera->moveLeft();
  } else if (event->key() == Qt::Key_S) {
    camera->moveBackward();
  } else if (event->key() == Qt::Key_D) {
    camera->moveRight();
  } else if (event->key() == Qt::Key_W) {
    camera->moveForward();
  } else if (event->key() == Qt::Key_Up) {
    camera->moveUp();
  } else if (event->key() == Qt::Key_Down) {
    camera->moveDown();
  } else if (event->key() == Qt::Key_Left) {
    camera->lookLeft();
  } else if (event->key() == Qt::Key_Right) {
    camera->lookRight();
  } else if (event->key() == Qt::Key_Plus) {
    camera->lookUp();
  } else if (event->key() == Qt::Key_Minus) {
    camera->lookDown();
  }
  std::cerr << *camera << std::endl;
}
