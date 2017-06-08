#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <QMainWindow>
#include <QKeyEvent>
class BigWindow;

class MainFrame : public QMainWindow {
  Q_OBJECT

public:
  MainFrame();

private slots:
  void onAddNew();
  void onLoadModel();
  void onLoadVertexShader();

private:
  BigWindow* _bigWindow;
};

#endif
