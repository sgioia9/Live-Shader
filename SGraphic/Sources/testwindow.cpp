#include "testwindow.hpp"

void TestWindow::initializeGL() {
  OglWindow::initializeGL();

  shader.reset(new Core::Shader(Core::ShaderBuilder::createBuilder() 
                                ->addSource("simple.vert")
                                ->addSource("simple.frag")
                                ->build()));
}

void TestWindow::paintGL() {
  glClearColor(0.7f, 0.2f, 0.5f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

