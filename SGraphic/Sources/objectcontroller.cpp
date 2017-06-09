#include <QWheelEvent>
#include <iostream>
#include "objectcontroller.hpp"
#include "worldobject.hpp"

ObjectController::ObjectController() { }

ObjectController::ObjectController(
    const std::shared_ptr<Core::WorldObject>& object)
  : _object(object) { }

void ObjectController::wheelEvent(QWheelEvent* event) {
  if (event->modifiers() & Qt::ControlModifier) {
    if (event->delta() > 0) {
      _object->scaleUp();
    } else {
      _object->scaleDown();
    }
  }
}
