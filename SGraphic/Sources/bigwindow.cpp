#include "mainframe.hpp"
#include "testwidget.hpp"
#include <QVBoxLayout>

#include "bigwindow.hpp"

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  oglWidget = new TestWidget();

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->setMargin(0);
  mainLayout->addWidget(oglWidget);

  setLayout(mainLayout);
}

void BigWindow::keyPressEvent(QKeyEvent* event) {
  std::cerr << "BigWindow event" << std::endl;
}
