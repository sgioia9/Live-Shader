#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <QMainWindow>
#include <QKeyEvent>

class BigWindow;
class QMenuBar;

class MainFrame : public QMainWindow {
  Q_OBJECT

public:
  MainFrame();

private slots:
  void onLoadModel();
  void onLoadVertexShader();
  void onLoadFragmentShader();
  void onRenderModel();
  void onReloadShaders();

private:
  BigWindow* _bigWindow;

  void setUpFileMenu(QMenuBar*);
  void setUpActionMenu(QMenuBar*);
};

#endif
