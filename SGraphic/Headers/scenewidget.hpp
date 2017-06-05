#ifndef SCENEWIDGET_HPP
#define SCENEWIDGET_HPP 

#include "camerawidget.hpp"
#include "model.hpp"
#include "worldobject.hpp"
#include "scene.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <iostream>
#include <QKeyEvent>


class SceneWidget: public CameraWidget {
public:
  static SceneWidget* get();

  SceneWidget(const SceneWidget&) = delete;
  void operator=(const SceneWidget&) = delete;

  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  void attachScene(Scene* scene);

  QSize sizeHint() const override;

  std::unique_ptr<Scene> _scene;
private:
  SceneWidget();
  static SceneWidget* instance;
};
#endif
