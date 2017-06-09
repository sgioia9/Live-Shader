#include <QWheelEvent>
#include <iostream>
#include "objectcontroller.hpp"

ObjectController::ObjectController() { }

ObjectController::ObjectController(
    const std::shared_ptr<Core::WorldObject>& object)
  : _object(object) { }

void ObjectController::wheelEvent(QWheelEvent* event) {
  if (event->modifiers() & Qt::ControlModifier) {
    if (event->delta() > 0) {
      std::cerr << "should scale up" << std::endl;
    } else {
      std::cerr << "should scale down" << std::endl;
    }
  }
}
