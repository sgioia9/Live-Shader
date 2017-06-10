#include "oglwidget.hpp"
#include <iostream>
#include <QFileDialog>

OglWidget::OglWidget(QWidget* parent) : QOpenGLWidget(parent) { }
OglWidget::~OglWidget() { delete loopTimer; }

void OglWidget::initializeGL() {
  initializeOpenGLFunctions();
  setFocusPolicy(Qt::ClickFocus);
  glEnable(GL_DEPTH_TEST);
  connect(
      context(), 
      SIGNAL(aboutToBeDestroyed()), 
      this, 
      SLOT(teardownGL()), 
      Qt::DirectConnection);

  loopTimer = new QTimer(this);
  connect(loopTimer, SIGNAL(timeout()), this, SLOT(update()));

  resumeAutoUpdate(); // start updating for max fps
}

void OglWidget::resizeGL(int width, int height) {
  (void)width;
  (void)height;
}

void OglWidget::paintGL() {
  glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

QSize OglWidget::sizeHint() const {
  return  QSize(800, 600);
}

void OglWidget::pauseAutoUpdate() {
  loopTimer->stop();
}

void OglWidget::resumeAutoUpdate() {
  loopTimer->start(0);
}

QString OglWidget::browseFileDialog(
    const QString& title, const std::string& directory, const QString& filters) {
  pauseAutoUpdate();
  QString fileName = 
    QFileDialog::getOpenFileName(this, title, QString::fromStdString(directory), filters);
  resumeAutoUpdate();
  return fileName;
}


void OglWidget::teardownGL() { }
