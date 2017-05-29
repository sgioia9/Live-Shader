
#include <memory>
#include <iostream>
#include <QTextEdit>
#include <QVBoxLayout>

#include "glconsole.hpp"
#include "logger.hpp"

GLConsole::GLConsole() {
  subscribeTo(Logger::get());
  std::cerr << "console subscribing" << std::endl;
  addConsoleTab();
}

void GLConsole::textUpdated(const std::string& newText) {
  consoleTextEdit->insertPlainText(QString::fromStdString(newText));
}

void GLConsole::addConsoleTab() {
  consoleTextEdit = new QTextEdit();
  consoleTextEdit->setReadOnly(true);
  addTab(consoleTextEdit, tr("Console"));
}
