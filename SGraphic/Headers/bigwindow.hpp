#ifndef BIGWINDOW_HPP
#define BIGWINDOW_HPP

#include <QWidget>

class OglWidget;
class MainFrame;

class BigWindow : public QWidget {
  Q_OBJECT

public:
  BigWindow(MainFrame*);

private:
  MainFrame* _mainFrame;
  OglWidget* oglWidget;

};
#endif
