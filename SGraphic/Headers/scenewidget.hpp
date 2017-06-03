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
#include <EventBus.hpp>

class GuiReadyEvent;

class SceneWidget: public CameraWidget, 
                   public EventHandler<GuiReadyEvent> {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;
  virtual void onEvent(GuiReadyEvent&) override;
  virtual ~SceneWidget();

  void attachScene(Scene* scene);

  QSize sizeHint() const override;

  std::unique_ptr<Scene> _scene;
private:
  HandlerRegistration* guiReadyRegistration;
};
#endif
