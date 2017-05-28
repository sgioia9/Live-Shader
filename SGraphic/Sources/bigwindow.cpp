#include "mainframe.hpp"
#include "testwidget.hpp"
#include <QVBoxLayout>

#include "bigwindow.hpp"


BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  oglWidget = new TestWidget();
  oglWidget->setFixedSize(QSize(800, 600));

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->setMargin(0);
  mainLayout->addWidget(oglWidget);

  setLayout(mainLayout);
}
