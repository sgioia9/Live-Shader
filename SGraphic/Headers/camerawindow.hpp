#ifndef CAMERAWINDOW_HPP
#define CAMERAWINDOW_HPP

#include <memory>

#include "fpcamera.hpp"
#include "oglwindow.hpp"

class CameraWindow : public OglWindow {
public:
  virtual void initializeGL() override;
  void keyPressEvent(QKeyEvent* event) override;

protected:
  std::unique_ptr<Core::FPCamera> camera;
};

#endif
