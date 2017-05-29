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
#include <EventBus.hpp>

class GuiReadyEvent;

class TestWidget : public CameraWidget, 
                   public EventHandler<GuiReadyEvent> {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;
  virtual void onEvent(GuiReadyEvent&) override;
  virtual ~TestWidget();

  QSize sizeHint() const override;

  std::unique_ptr<Core::Shader> shader;
  std::unique_ptr<Core::WorldObject> object;
private:
  HandlerRegistration* guiReadyRegistration;
};
#endif
