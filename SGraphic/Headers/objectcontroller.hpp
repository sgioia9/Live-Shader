#ifndef OBJECTCONTROLLER_HPP
#define OBJECTCONTROLLER_HPP

#include <memory>

namespace Core {
  class WorldObject;
}

class QWheelEvent;
class QMouseEvent;
class QPoint;

class ObjectController {
public:
  ObjectController(const std::shared_ptr<Core::WorldObject>&);

  virtual void wheelEvent(QWheelEvent*);
  virtual void mouseMoveEvent(QMouseEvent*);
  virtual void mouseReleaseEvent(QMouseEvent*);

protected:
  ObjectController();

private:
  std::shared_ptr<Core::WorldObject> _object;

  std::unique_ptr<QPoint> _lastCursorPosition;

  float _baseAngularSpeed;
};

class NullObjectController : public ObjectController {
public: 
  NullObjectController() { }

  virtual void wheelEvent(QWheelEvent*) override { }
  virtual void mouseMoveEvent(QMouseEvent*) override { }
  virtual void mouseReleaseEvent(QMouseEvent*) override { }

};

#endif
