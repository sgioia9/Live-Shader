#ifndef OGLWINDOW_HPP
#define OGLWINDOW_HPP

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class OglWindow : public QOpenGLWindow,
                  protected QOpenGLFunctions {
Q_OBJECT

public:
  virtual void initializeGL();
  virtual void resizeGL(int width, int height);
  virtual void paintGL();
protected slots:
  virtual void teardownGL();
};
                

#endif
