#ifndef BIGWINDOW_HPP
#define BIGWINDOW_HPP

#include <QWidget>
#include <QKeyEvent>

class OglWidget;
class MainFrame;

class BigWindow : public QWidget {
  Q_OBJECT

public:
  BigWindow(MainFrame*);

protected:
  void keyPressEvent(QKeyEvent*) override;

private:
  MainFrame* _mainFrame;
  OglWidget* oglWidget;

};
#endif
