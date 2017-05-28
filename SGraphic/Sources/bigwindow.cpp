#include "mainframe.hpp"
#include "oglwidget.hpp"
#include "bigwindow.hpp"

#include <QVBoxLayout>

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  oglWidget = new OglWidget();

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addWidget(oglWidget);

  setLayout(mainLayout);
}
