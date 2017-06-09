#ifndef CAMERAWIDGET_HPP
#define CAMERAWIDGET_HPP

#include <memory>

#include "camcontroller.hpp"
#include "fpcamera.hpp"
#include "oglwidget.hpp"

class CameraWidget : public OglWidget {
public:
  virtual void initializeGL() override;
  virtual ~CameraWidget();

protected:
  virtual void keyPressEvent(QKeyEvent*) override;
  virtual void wheelEvent(QWheelEvent*) override;

protected:
  std::shared_ptr<CamController> _camController;
};

#endif
