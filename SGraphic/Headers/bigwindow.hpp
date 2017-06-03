#ifndef BIGWINDOW_HPP
#define BIGWINDOW_HPP

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include "displayedmodellabel.hpp"
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
  MainFrame* _mainFrame;
  OglWidget* _oglWidget;
  DisplayedModelLabel* _displayedModelLabel;
  EditorsArea* _editorsArea;

};
#endif
