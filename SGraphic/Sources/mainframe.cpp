#include <QtWidgets>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QShowEvent>
#include <iostream>

#include "bigwindow.hpp"
#include "mainframe.hpp"
#include "editorsarea.hpp"
#include "editorstabs.hpp"
#include "vertexshadereditor.hpp"

MainFrame::MainFrame() { 
  QMenuBar* menuBar = new QMenuBar;
  QMenu* menuWindow = menuBar->addMenu(tr("&File"));

  QAction* loadModel = new QAction(menuWindow);
  loadModel->setText(tr("Load model"));
  menuWindow->addAction(loadModel);
  connect(loadModel, &QAction::triggered, this, &MainFrame::onLoadModel);

  QAction* loadVertexShader= new QAction(menuWindow);
  loadVertexShader->setText(tr("Load vertex shader"));
  menuWindow->addAction(loadVertexShader);
  connect(loadVertexShader, &QAction::triggered, this, &MainFrame::onLoadVertexShader);

  setMenuBar(menuBar);
  onAddNew();
}

void MainFrame::onAddNew() {
  if (!centralWidget()) {
    _bigWindow = new BigWindow(this);
    setCentralWidget(_bigWindow);
  } else {
    QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
  }
}

void MainFrame::onLoadModel() {
  _bigWindow->onLoadModel();
}

void MainFrame::onLoadVertexShader() {
  _bigWindow->_editorsArea->_tabs->_vertexShaderEditor->load();
}


