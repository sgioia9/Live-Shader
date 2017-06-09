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
  CamController();
  CamController(
      const std::shared_ptr<Core::FPCamera>&,
      CameraWidget*);

  void setCamera(const std::shared_ptr<Core::FPCamera>& camera);
  void setWidget(CameraWidget* widget);
  virtual void keyPressEvent(QKeyEvent*);
  virtual void mousePressEvent(QMouseEvent*);
  virtual void wheelEvent(QWheelEvent*);
 
private:
  std::shared_ptr<Core::FPCamera> _camera;
  CameraWidget* _widget;
};

class NullCamController : public CamController {
  void keyPressEvent(QKeyEvent*) override { }
  void mousePressEvent(QMouseEvent*) override { }
  void wheelEvent(QWheelEvent*) override { }
};

#endif
