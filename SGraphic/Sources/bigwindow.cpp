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
  displayedModelLayout->addWidget(_displayedModelLabel);

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
  QString selectedFile =  
    _sceneWidget->browseFileDialog(tr("Load model"), "", tr("Models (*.obj)"));
  _displayedModelLabel->displayModelName(selectedFile.toStdString());
  Configuration::get().setPathToModel(selectedFile.toStdString());
}

void BigWindow::onRender() {
  _sceneWidget->onNewConfig(Configuration::get().getModelInfo());
}
