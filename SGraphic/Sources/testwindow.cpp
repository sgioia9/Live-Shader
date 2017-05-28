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
  object.reset(
      new Core::WorldObject(
        std::make_shared<Core::Model>("nanosuit/nanosuit.obj")));

  object->_transform = glm::scale(object->_transform, glm::vec3(0.2f, 0.2f, 0.2f));

  shader->use();
}

void TestWindow::teardownGL() { }

void TestWindow::paintGL() {
  OglWindow::paintGL();

  shader->uniformMatrix("model", object->_transform);
  shader->uniformMatrix("vpMatrix", camera->vp_matrix());

  object->_model->draw(*shader);
}
