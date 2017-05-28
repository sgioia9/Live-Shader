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
  geomodel.reset(new Core::Model("nanosuit/nanosuit.obj"));

  *model = glm::scale(*model, glm::vec3(0.2f, 0.2f, 0.2f));

  shader->use();
}

void TestWindow::teardownGL() { }

void TestWindow::paintGL() {
  OglWindow::paintGL();

  geomodel->draw(*shader);

  shader->uniformMatrix("model", *model);
  shader->uniformMatrix("vpMatrix", camera->vp_matrix());

}
