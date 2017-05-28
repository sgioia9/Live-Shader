#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <QMainWindow>

class MainFrame : public QMainWindow {
  Q_OBJECT

public:
  MainFrame();

private slots:
  void onAddNew();
};

#endif
