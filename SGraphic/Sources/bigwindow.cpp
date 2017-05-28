#include "mainframe.hpp"
#include "testwidget.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "editorsarea.hpp"

#include "bigwindow.hpp"

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  _oglWidget = new TestWidget();
  _editorsArea = new EditorsArea(this);

  QHBoxLayout* mainLayout = new QHBoxLayout();

  QVBoxLayout* openglAndRenderbtnLayout = new QVBoxLayout();
  openglAndRenderbtnLayout->addWidget(_oglWidget);
  openglAndRenderbtnLayout->addWidget(new QPushButton(tr("Render")));
  openglAndRenderbtnLayout->setMargin(0);

  QWidget* openglAndRenderbtnWidget = new QWidget();
  openglAndRenderbtnWidget->setMinimumSize(QSize(1000, 700));
  openglAndRenderbtnWidget->setLayout(openglAndRenderbtnLayout);

  mainLayout->addWidget(openglAndRenderbtnWidget);
  mainLayout->addWidget(_editorsArea);

  setLayout(mainLayout);
}
