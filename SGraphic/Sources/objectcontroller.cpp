#include <QWheelEvent>
#include <QDebug>
#include <iostream>
#include "objectcontroller.hpp"
#include "worldobject.hpp"

ObjectController::ObjectController() { }

ObjectController::ObjectController(
    const std::shared_ptr<Core::WorldObject>& object)
  : _object(object), _baseAngularSpeed(0.01f) { }

void ObjectController::wheelEvent(QWheelEvent* event) {
  if (event->modifiers() & Qt::ControlModifier) {
    if (event->delta() > 0) {
      _object->scaleUp();
    } else {
      _object->scaleDown();
    }
  }
}

void ObjectController::mouseMoveEvent(QMouseEvent* event) {
  if (!_lastCursorPosition) {
    _lastCursorPosition.reset(new QPoint(event->pos()));
  }   
  QPoint currentPosition = event->pos();
  QPoint deltaPosition = currentPosition - *_lastCursorPosition;
  _object->rotateYAxis(_baseAngularSpeed * deltaPosition.x());
  _object->rotateXAxis(_baseAngularSpeed * deltaPosition.y());
  *_lastCursorPosition = currentPosition;
}

void ObjectController::mouseReleaseEvent(QMouseEvent*) {
  _lastCursorPosition.release();
}
