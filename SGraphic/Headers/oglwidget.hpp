#ifndef OGLWIDGET_HPP
#define OGLWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QTimer>

class GuiReadyEvent;

class OglWidget : public QOpenGLWidget,
                  protected QOpenGLExtraFunctions { 
Q_OBJECT

public:
  OglWidget(QWidget* parent = 0);
  virtual void initializeGL() override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL() override;
  virtual QSize sizeHint() const override;
protected slots:
  virtual void teardownGL();
/*
private:
  QTimer* loopTimer;
  */
};
                

#endif
