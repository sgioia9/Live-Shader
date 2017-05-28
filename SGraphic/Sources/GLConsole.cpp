
#include <memory>
#include <iostream>
#include <QTextEdit>
#include <QVBoxLayout>

#include "glconsole.hpp"
#include "logger.hpp"

GLConsole::GLConsole() {
  subscribeTo(Logger::get());
  addNewTab("Console");
}

void GLConsole::textUpdated(const std::string& newText) {
  std::cerr << newText;
}

void GLConsole::addNewTab(const QString& tabName) {
  QTextEdit* tabContent = new QTextEdit();
  tabContent->setReadOnly(true);
  addTab(tabContent, tabName);
}
