#ifndef CAMCONTROLLER_HPP
#define CAMCONTROLLER_HPP

#include <memory>

class QKeyEvent;
class CameraWidget;
class QMouseEvent;
class QWheelEvent;

namespace Core { class FPCamera; }

class CamController {
public:
  CamController(const std::shared_ptr<Core::FPCamera>&, CameraWidget*);

  virtual void keyPressEvent(QKeyEvent*);
  virtual void mousePressEvent(QMouseEvent*);
  virtual void wheelEvent(QWheelEvent*);

protected:
  CamController();
 
private:
  std::shared_ptr<Core::FPCamera> _camera;
  CameraWidget* _widget;
};

class NullCamController : public CamController {
public:
  NullCamController() {} 

  void keyPressEvent(QKeyEvent*) override { }
  void mousePressEvent(QMouseEvent*) override { }
  void wheelEvent(QWheelEvent*) override { }
};

#endif
