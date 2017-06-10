#ifndef OGLWIDGET_HPP
#define OGLWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QTimer>

class GuiReadyEvent;

class OglWidget : public QOpenGLWidget,
                  public QOpenGLExtraFunctions { 
Q_OBJECT

public:
  OglWidget(QWidget* parent = 0);
  ~OglWidget();
  virtual void initializeGL() override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL() override;
  virtual QSize sizeHint() const override;
  void pauseAutoUpdate();
  void resumeAutoUpdate();
  QString browseFileDialog(
      const QString& title, const std::string& directory, const QString& filters);

protected slots:
  virtual void teardownGL();
private:
  QTimer* loopTimer;
};
                

#endif
