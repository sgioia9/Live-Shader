#ifndef BIGWINDOW_HPP
#define BIGWINDOW_HPP

#include <QWidget>
#include <QKeyEvent>

class OglWidget;
class QPushButton;
class MainFrame;
class EditorsArea;

class BigWindow : public QWidget {
  Q_OBJECT

public:
  BigWindow(MainFrame*);

private:
  MainFrame* _mainFrame;
  OglWidget* _oglWidget;
  EditorsArea* _editorsArea;

};
#endif
