#include "mainframe.hpp"
#include "testwindow.hpp"
#include <QVBoxLayout>

#include "bigwindow.hpp"


BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  oglWidget = new TestWindow();
  oglWidget->setFixedSize(QSize(800, 600));

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->setMargin(0);
  mainLayout->addWidget(oglWidget);

  setLayout(mainLayout);
}
