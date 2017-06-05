#ifndef BIGWINDOW_HPP
#define BIGWINDOW_HPP

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QOpenGLExtraFunctions>
#include "displayedmodellabel.hpp"
#include <memory>
#include <logger.hpp>

class SceneWidget;
class QPushButton;
class MainFrame;
class EditorsArea;

class BigWindow : public QWidget {
  Q_OBJECT

public:
  BigWindow(MainFrame*);

private slots:
  void onLoadModel();
  void onRender();

private:
  MainFrame* _mainFrame;
  SceneWidget* _sceneWidget;
  DisplayedModelLabel* _displayedModelLabel;
  EditorsArea* _editorsArea;
};
#endif
