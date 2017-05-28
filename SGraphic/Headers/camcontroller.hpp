#ifndef CAMCONTROLLER_HPP
#define CAMCONTROLLER_HPP

#include <memory>

class QKeyEvent;
class CameraWidget;
class QMouseEvent;

namespace Core { class FPCamera; }

class CamController {
public:
  CamController();
  CamController(
      const std::shared_ptr<Core::FPCamera>& camera,
      const std::shared_ptr<CameraWidget>& widget);

  void setCamera(const std::shared_ptr<Core::FPCamera>& camera);
  void setWidget(const std::shared_ptr<CameraWidget>& widget);
  void keyPressEvent(QKeyEvent*);
  void mousePressEvent(QMouseEvent*);
 
private:
  std::shared_ptr<Core::FPCamera> _camera;
  std::shared_ptr<CameraWidget> _widget;
};

#endif
