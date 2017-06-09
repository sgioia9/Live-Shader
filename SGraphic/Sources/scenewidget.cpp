#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <QDebug>

#include "scenewidget.hpp"
#include "resourceloader.hpp"
#include "mainframe.hpp"
#include "scene.hpp"
#include "configscene.hpp"
#include "vertexshadereditor.hpp"
#include "fragmentshadereditor.hpp"
#include "logger.hpp"
#include "configuration.hpp"
#include "objectcontroller.hpp"

SceneWidget* SceneWidget::instance = nullptr;

SceneWidget* SceneWidget::get() {
  if (!instance) instance = new SceneWidget();
  return instance;
}

SceneWidget::SceneWidget() { 
  shouldReloadShaders = false;
  _objectController.reset(new NullObjectController());
}
SceneWidget::~SceneWidget() { }

void SceneWidget::initializeGL() {
  CameraWidget::initializeGL();
  _scene.reset(new NullScene());
}

void SceneWidget::paintGL() {
  CameraWidget::paintGL();
  _scene->draw();
  if (!newModelEvents.empty()) {
    processEvent();
  }
  if (shouldReloadShaders) {
    reloadShaders();
    shouldReloadShaders = false;
  }
}

QSize SceneWidget::sizeHint() const {
  return QSize(800, 600);
}

void SceneWidget::processEvent() {
  const ModelInfo& event = newModelEvents.front();
  try {
    ConfigScene* newScene = new ConfigScene(event);
    _scene.reset(newScene);
    _camController.reset(new CamController(_scene->_camera, this));
    _objectController.reset(new ObjectController(_scene->_object));
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
  newModelEvents.pop();
}

void SceneWidget::onNewConfig(const ModelInfo& info) {
  newModelEvents.push(info);
}

void SceneWidget::onReloadShaders() {
  shouldReloadShaders = true;
}

void SceneWidget::reloadShaders() {
  Logger::get().logLine("Building shaders...");
  try {
    _scene->resetShader(
        new Core::Shader(
          Core::ShaderBuilder::createBuilder() 
          ->addVertexShaderSource(VertexShaderEditor::get()->getText())
          ->addFragmentShaderSource(FragmentShaderEditor::get()->getText())
          ->build()));
    Logger::get().logLine("Shaders built");
  } catch (const std::string& err) {
    Logger::get().logLine(err);
  }
}


void SceneWidget::keyPressEvent(QKeyEvent* event) {
  CameraWidget::keyPressEvent(event);
}

void SceneWidget::mouseMoveEvent(QMouseEvent* event) {
  _objectController->mouseMoveEvent(event);
}

void SceneWidget::mouseReleaseEvent(QMouseEvent* event) {
  _objectController->mouseReleaseEvent(event);
}

void SceneWidget::wheelEvent(QWheelEvent* event) {
  CameraWidget::wheelEvent(event);
  _objectController->wheelEvent(event);
}
