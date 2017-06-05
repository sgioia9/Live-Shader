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
#include "displayedmodellabel.hpp"
#include "camerawidget.hpp"

#include "bigwindow.hpp"

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  _sceneWidget = new SceneWidget();
  _editorsArea = new EditorsArea(this);
  _displayedModelLabel = new DisplayedModelLabel();

  QHBoxLayout* mainLayout = new QHBoxLayout();

  
  /* Displayed model widget */
  QHBoxLayout* displayedModelLayout = new QHBoxLayout();
  displayedModelLayout->addWidget(_displayedModelLabel);

  QPushButton* loadModelButton = new QPushButton(tr("Load model"));
  connect(loadModelButton, &QAbstractButton::clicked, this, &BigWindow::onLoadModel);
  displayedModelLayout->addWidget(loadModelButton);

  QWidget* displayedModelWidget = new QWidget();
  displayedModelWidget->setLayout(displayedModelLayout);
  /* --------------------- */

  QVBoxLayout* openglAndRenderbtnLayout = new QVBoxLayout();
  openglAndRenderbtnLayout->addWidget(_sceneWidget);
  openglAndRenderbtnLayout->addWidget(displayedModelWidget);
  
  QPushButton* renderButton = new QPushButton(tr("Render"));
  connect(renderButton, &QAbstractButton::clicked, this, &BigWindow::onRender);
  openglAndRenderbtnLayout->addWidget(renderButton);

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
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "/home",
                                                  tr("Images (*.png *.xpm *.jpg)"));
  _sceneWidget->resumeAutoUpdate();
}

void BigWindow::onRender() {
  std::cerr << "onRender clicked" << std::endl;
}
