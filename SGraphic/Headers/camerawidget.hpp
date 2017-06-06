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
  void keyPressEvent(QKeyEvent*) override;
  void mousePressEvent(QMouseEvent*) override;

protected:
  std::shared_ptr<CamController> controller;
};

#endif
