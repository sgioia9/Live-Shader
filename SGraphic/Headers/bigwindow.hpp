#ifndef BIGWINDOW_HPP
#define BIGWINDOW_HPP

#include <QWidget>
#include <QKeyEvent>
#include <memory>
#include <logger.hpp>

class OglWidget;
class QPushButton;
class MainFrame;
class EditorsArea;

class BigWindow : public QWidget {
  Q_OBJECT

public:
  BigWindow(MainFrame*);

private:
  std::shared_ptr<Logger> logger;

  MainFrame* _mainFrame;
  OglWidget* _oglWidget;
  EditorsArea* _editorsArea;

};
#endif
