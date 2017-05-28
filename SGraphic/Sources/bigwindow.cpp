#include "mainframe.hpp"
#include "testwidget.hpp"
#include <QHBoxLayout>
#include "editorsarea.hpp"

#include "bigwindow.hpp"

BigWindow::BigWindow(MainFrame* mainFrame) : _mainFrame(mainFrame) {
  _oglWidget = new TestWidget();
  _editorsArea = new EditorsArea(this);

  QHBoxLayout* mainLayout = new QHBoxLayout;
  mainLayout->addWidget(_oglWidget);
  mainLayout->addWidget(_editorsArea);

  setLayout(mainLayout);
}
