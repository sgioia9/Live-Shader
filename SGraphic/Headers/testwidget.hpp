#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "camerawidget.hpp"
#include "shader.hpp"
#include "model.hpp"
#include "worldobject.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <iostream>
#include <QKeyEvent>

class TestWidget : public CameraWidget {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  std::unique_ptr<Core::Shader> shader;
  std::unique_ptr<Core::WorldObject> object;
};

#endif
