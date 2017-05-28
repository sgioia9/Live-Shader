#ifndef CAMERAWIDGET_HPP
#define CAMERAWIDGET_HPP

#include <memory>

#include "fpcamera.hpp"
#include "oglwidget.hpp"

class CameraWidget : public OglWidget {
public:
  virtual void initializeGL() override;
  void keyPressEvent(QKeyEvent* event) override;

protected:
  std::unique_ptr<Core::FPCamera> camera;
};

#endif
