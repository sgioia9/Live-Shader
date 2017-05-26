#ifndef OGLWINDOW_HPP
#define OGLWINDOW_HPP

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class OglWindow : public QOpenGLWindow,
                  protected QOpenGLFunctions {
Q_OBJECT

public:
  void initializeGL();
  void resizeGL(int width, int height);
  void paintGL();
protected slots:
  void teardownGL();

};
                

#endif
