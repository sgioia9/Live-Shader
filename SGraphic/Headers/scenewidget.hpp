#ifndef SCENEWIDGET_HPP
#define SCENEWIDGET_HPP 

#include "camerawidget.hpp"
#include "shader.hpp"
#include "model.hpp"
#include "worldobject.hpp"
#include "scene.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <iostream>
#include <QKeyEvent>


class SceneWidget: public CameraWidget {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  void attachScene(Scene* scene);

  QSize sizeHint() const override;

  std::unique_ptr<Scene> _scene;
};
#endif
