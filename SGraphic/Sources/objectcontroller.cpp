#include <QWheelEvent>
#include <iostream>
#include "objectcontroller.hpp"

ObjectController::ObjectController() { }

ObjectController::ObjectController(
    const std::shared_ptr<Core::WorldObject>& object)
  : _object(object) { }

void ObjectController::wheelEvent(QWheelEvent* event) {
  std::cerr << "obj controller event" << std::endl; 
}
