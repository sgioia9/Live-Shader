#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "scenewidget.hpp"
#include "resourceloader.hpp"
#include "mainframe.hpp"
#include "scene.hpp"
#include "configscene.hpp"
#include "vertexshadereditor.hpp"
#include "fragmentshadereditor.hpp"
#include "logger.hpp"
#include "configuration.hpp"

SceneWidget* SceneWidget::instance = nullptr;

SceneWidget* SceneWidget::get() {
  if (!instance) instance = new SceneWidget();
  return instance;
}

SceneWidget::SceneWidget() { 
  shouldReloadShaders = false;
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
    controller.reset(new CamController());
    _scene->attachController(controller);
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
