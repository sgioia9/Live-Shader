#include "mainframe.hpp"
#include "oglwidget.hpp"
#include "bigwindow.hpp"

#include <QVBoxLayout>

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  oglWidget = new OglWidget();
  oglWidget->setFixedSize(QSize(800, 600));

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->setMargin(0);
  mainLayout->addWidget(oglWidget);

  setLayout(mainLayout);
}
