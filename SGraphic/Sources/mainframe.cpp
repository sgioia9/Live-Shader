#include <QtWidgets>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QShowEvent>
#include <iostream>

#include "bigwindow.hpp"
#include "mainframe.hpp"

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

void MainFrame::onAddNew() {
  if (!centralWidget()) {
    setCentralWidget(new BigWindow(this));
  } else {
    QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
  }
}


