#ifndef SCENEWIDGET_HPP
#define SCENEWIDGET_HPP 

#include "camerawidget.hpp"
#include "model.hpp"
#include "worldobject.hpp"
#include "scene.hpp"
#include "configuration.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <iostream>
#include <queue>
#include <QKeyEvent>

class SceneWidget: public CameraWidget {
public:
  static SceneWidget* get();
  ~SceneWidget();

  SceneWidget(const SceneWidget&) = delete;
  void operator=(const SceneWidget&) = delete;

  virtual void initializeGL() override;
  virtual void paintGL() override;

  void onNewConfig(const ModelInfo& info);
  void onReloadShaders();

  QSize sizeHint() const override;

private:
  SceneWidget();
  void processEvent();
  void reloadShaders();

  std::unique_ptr<Scene> _scene;
  std::queue<ModelInfo> newModelEvents;

  bool shouldReloadShaders;

  static SceneWidget* instance;
};
#endif
