#ifndef OBJECTCONTROLLER_HPP
#define OBJECTCONTROLLER_HPP

#include <memory>

namespace Core {
  class WorldObject;
}

class QWheelEvent;

class ObjectController {
public:
  ObjectController(const std::shared_ptr<Core::WorldObject>&);

  virtual void wheelEvent(QWheelEvent*);

protected:
  ObjectController();

private:
  std::shared_ptr<Core::WorldObject> _object;
};

class NullObjectController : public ObjectController {
public: 
  NullObjectController() { }

  virtual void wheelEvent(QWheelEvent*) override { }

};

#endif
