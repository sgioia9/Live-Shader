#include <QtWidgets>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <iostream>

#include "mainframe.hpp"
#include "bigwindow.hpp"

MainFrame::MainFrame() { 
  QMenuBar* menuBar = new QMenuBar;
  QMenu* menuWindow = menuBar->addMenu(tr("&Window"));
  QAction* addNew = new QAction(menuWindow);
  addNew->setText(tr("Add new"));
  menuWindow->addAction(addNew);
  connect(addNew, &QAction::triggered, this, &MainFrame::onAddNew);
  setMenuBar(menuBar);

  onAddNew();
}

/*
void MainFrame::keyPressEvent(QKeyEvent*) {
  std::cerr << "MainFrame event" << std::endl;
}
*/

void MainFrame::onAddNew() {
  if (!centralWidget()) {
    setCentralWidget(new BigWindow(this));
  } else {
    QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
  }
}


