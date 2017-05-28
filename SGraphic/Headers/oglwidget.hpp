#ifndef OGLWIDGET_HPP
#define OGLWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QTimer>

class OglWidget : public QOpenGLWidget,
                  protected QOpenGLExtraFunctions {
Q_OBJECT

public:
  OglWidget(QWidget* parent = 0);
  virtual void initializeGL();
  virtual void resizeGL(int width, int height);
  virtual void paintGL();
protected slots:
  virtual void teardownGL();
private:
  QTimer* loopTimer;
};
                

#endif
