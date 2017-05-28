
#include <memory>
#include <iostream>
#include <QTextEdit>
#include <QVBoxLayout>

#include "glconsole.hpp"

GLConsole::GLConsole(const std::shared_ptr<Logger>& logger) 
  : _logger(logger) { 
  subscribeTo(_logger);  
  addNewTab(tr("Console"));
}

void GLConsole::textUpdated(const std::string& newText) {
  std::cerr << newText;
}

void GLConsole::addNewTab(const QString& tabName) {
  QTextEdit* tabContent = new QTextEdit();
  tabContent->setReadOnly(true);
  addTab(tabContent, tabName);
}
