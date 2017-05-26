#include "oglwindow.hpp"

void OglWindow::initializeGL() {
  initializeOpenGLFunctions();
  connect(
      context(), 
      SIGNAL(aboutToBeDestroyed()), 
      this, 
      SLOT(teardownGL()), 
      Qt::DirectConnection);
}

void OglWindow::resizeGL(int width, int height) {
  (void)width;
  (void)height;
}

void OglWindow::paintGL() {
  glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void OglWindow::teardownGL() {
  // TODO:
}
