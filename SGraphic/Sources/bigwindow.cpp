#include "mainframe.hpp"
#include "scenewidget.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "editorsarea.hpp"
#include "glconsole.hpp"
#include "oglwidget.hpp"
#include "displayedmodellabel.hpp"
#include "camerawidget.hpp"

#include "bigwindow.hpp"

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  _oglWidget = new SceneWidget();
  _editorsArea = new EditorsArea(this);
  _displayedModelLabel = new DisplayedModelLabel();

  QHBoxLayout* mainLayout = new QHBoxLayout();

  QHBoxLayout* displayedModelLayout = new QHBoxLayout();
  displayedModelLayout->addWidget(_displayedModelLabel);
  displayedModelLayout->addWidget(new QPushButton(tr("Load model")));
  QWidget* displayedModelWidget = new QWidget();
  displayedModelWidget->setLayout(displayedModelLayout);

  QVBoxLayout* openglAndRenderbtnLayout = new QVBoxLayout();
  openglAndRenderbtnLayout->addWidget(_oglWidget);
  openglAndRenderbtnLayout->addWidget(displayedModelWidget);
  openglAndRenderbtnLayout->addWidget(new QPushButton(tr("Render")));
  openglAndRenderbtnLayout->addWidget(new GLConsole);
  openglAndRenderbtnLayout->setMargin(0);

  QWidget* openglAndRenderbtnWidget = new QWidget();
  openglAndRenderbtnWidget->setMinimumSize(QSize(1000, 700));
  openglAndRenderbtnWidget->setLayout(openglAndRenderbtnLayout);

  mainLayout->addWidget(openglAndRenderbtnWidget);
  mainLayout->addWidget(_editorsArea);

  setLayout(mainLayout);
}
