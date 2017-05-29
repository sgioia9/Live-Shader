#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <QMainWindow>
#include <QKeyEvent>


class QShowEvent;

class MainFrame : public QMainWindow {
  Q_OBJECT

public:
  MainFrame();

  void showEvent(QShowEvent*);

 /* 
protected:
  void keyPressEvent(QKeyEvent*) override;
  */

private slots:
  void onAddNew();
};

#endif
