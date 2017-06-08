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
#include "fragmentshadereditor.hpp"

MainFrame::MainFrame() { 
  QMenuBar* menuBar = new QMenuBar;

  setUpFileMenu(menuBar);
  setUpActionMenu(menuBar);

  setMenuBar(menuBar);
  onAddNew();
}

void MainFrame::setUpFileMenu(QMenuBar* menuBar) {
  QMenu* menuFile= menuBar->addMenu(tr("&File"));

  QAction* loadModel = new QAction(menuFile);
  loadModel->setText(tr("Load model"));
  loadModel->setShortcut(tr("Ctrl+o"));
  menuFile->addAction(loadModel);
  connect(loadModel, &QAction::triggered, this, &MainFrame::onLoadModel);

  QAction* loadVertexShader= new QAction(menuFile);
  loadVertexShader->setText(tr("Load vertex shader"));
  loadVertexShader->setShortcut(tr("CTRL+v"));
  menuFile->addAction(loadVertexShader);
  connect(loadVertexShader, &QAction::triggered, this, &MainFrame::onLoadVertexShader);

  QAction* loadFragmentShader = new QAction(menuFile);
  loadFragmentShader->setText(tr("Load fragment shader"));
  loadFragmentShader->setShortcut(tr("CTRL+f"));
  menuFile->addAction(loadFragmentShader);
  connect(loadFragmentShader, &QAction::triggered, this, &MainFrame::onLoadFragmentShader);
  
  menuFile->addSeparator();

  QAction* exit = new QAction(menuFile);
  exit->setText(tr("Exit"));
  menuFile->addAction(exit);
  connect(exit, &QAction::triggered, this, &MainFrame::close);
}

void MainFrame::setUpActionMenu(QMenuBar* menuBar) {
  QMenu* menuAction = menuBar->addMenu(tr("&Action"));
  
  QAction* rebuildShaders = new QAction(menuAction);
  rebuildShaders->setText(tr("Rebuild shaders"));
  rebuildShaders->setShortcut(tr("F5"));
  menuAction->addAction(rebuildShaders);
  // TODO: connect(...)
  
  QAction* renderModel = new QAction(menuAction);
  renderModel->setText(tr("Render model"));
  renderModel->setShortcut(tr("F6"));
  menuAction->addAction(renderModel);
  connect(renderModel, &QAction::triggered, this, &MainFrame::onRenderModel);
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

void MainFrame::onRenderModel() {
  _bigWindow->onRender();
}

void MainFrame::onLoadVertexShader() {
  _bigWindow->_editorsArea->_tabs->_vertexShaderEditor->load();
}

void MainFrame::onLoadFragmentShader() {
  _bigWindow->_editorsArea->_tabs->_fragmentShaderEditor->load();
}


