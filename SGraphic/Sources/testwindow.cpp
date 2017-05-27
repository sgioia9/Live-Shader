#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "testwindow.hpp"
#include "resourceloader.hpp"


void TestWindow::initializeGL() {
  CameraWindow::initializeGL();

  shader.reset(new Core::Shader(Core::ShaderBuilder::createBuilder() 
                                ->addSource("simple.vert")
                                ->addSource("simple.frag")
                                ->build()));
  model.reset(new glm::mat4());
  view.reset(new glm::mat4());
  projection.reset(new glm::mat4());
  geomodel.reset(new Core::Model("nanosuit/nanosuit.obj"));

  *model = glm::scale(*model, glm::vec3(0.2f, 0.2f, 0.2f));
  *view = glm::translate(*view, glm::vec3(0.0f, 0.0f, -3.0f));
  *projection = glm::perspective(glm::radians(45.0f), 1.0f * width() / height(), 0.1f, 100.0f);

  shader->use();
}

void TestWindow::teardownGL() { }

void TestWindow::paintGL() {
  OglWindow::paintGL();

  *view = camera->view();
  geomodel->draw(*shader);

  shader->uniformMatrix("model", *model);
  shader->uniformMatrix("view", *view);
  shader->uniformMatrix("projection", *projection);

}
