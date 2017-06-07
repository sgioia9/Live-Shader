#include "mainframe.hpp"
#include "scenewidget.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "editorsarea.hpp"
#include "glconsole.hpp"
#include "oglwidget.hpp"
#include "configscene.hpp"
#include "configuration.hpp"
#include "displayedmodellabel.hpp"
#include "camerawidget.hpp"
#include "vertexshadereditor.hpp"
#include "fragmentshadereditor.hpp"

#include "bigwindow.hpp"

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  _sceneWidget = SceneWidget::get();
  _editorsArea = new EditorsArea(this);
  _displayedModelLabel = new DisplayedModelLabel();

  QHBoxLayout* mainLayout = new QHBoxLayout();

  
  /* Displayed model widget */
  QHBoxLayout* displayedModelLayout = new QHBoxLayout();

  QVBoxLayout* buttonsLayout = new QVBoxLayout();

  QPushButton* loadModelButton = new QPushButton(tr("Load model"));
  connect(loadModelButton, &QAbstractButton::clicked, this, &BigWindow::onLoadModel);

  QPushButton* renderButton = new QPushButton(tr("Render"));
  connect(renderButton, &QAbstractButton::clicked, this, &BigWindow::onRender);

  buttonsLayout->addWidget(loadModelButton);
  buttonsLayout->addWidget(renderButton);

  QWidget* buttonsWidget = new QWidget();
  buttonsWidget->setLayout(buttonsLayout);

  displayedModelLayout->addWidget(_displayedModelLabel);
  displayedModelLayout->addWidget(buttonsWidget);

  QWidget* displayedModelWidget = new QWidget();
  displayedModelWidget->setLayout(displayedModelLayout);
  /* --------------------- */

  QVBoxLayout* openglAndRenderbtnLayout = new QVBoxLayout();
  openglAndRenderbtnLayout->addWidget(_sceneWidget);
  openglAndRenderbtnLayout->addWidget(displayedModelWidget);
  

  openglAndRenderbtnLayout->addWidget(new GLConsole);
  openglAndRenderbtnLayout->setMargin(0);

  QWidget* openglAndRenderbtnWidget = new QWidget();
  openglAndRenderbtnWidget->setMinimumSize(QSize(1000, 700));
  openglAndRenderbtnWidget->setLayout(openglAndRenderbtnLayout);

  mainLayout->addWidget(openglAndRenderbtnWidget);
  mainLayout->addWidget(_editorsArea);

  setLayout(mainLayout);
}

void BigWindow::onLoadModel() {
  _sceneWidget->pauseAutoUpdate();
  QString fileName = QFileDialog::getOpenFileName(this, tr("Load model"),
                                                  "",
                                                  tr("Models (*.obj)"));
  Logger::get().logLine("Selected: " + fileName.toStdString());
  _displayedModelLabel->displayModelName(fileName.toStdString());
  Configuration::get().setPathToModel(fileName.toStdString());
  _sceneWidget->resumeAutoUpdate();
}

void BigWindow::onRender() {
  _sceneWidget->onNewConfig(Configuration::get().getModelInfo());
}
