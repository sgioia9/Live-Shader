#ifndef GLCONSOLE_HPP
#define GLCONSOLE_HPP

#include <QTabWidget>
#include <QTextEdit>
#include <memory>
#include "loggerlistener.hpp"

class Logger;

class GLConsole : public QTabWidget, public LoggerListener {
  Q_OBJECT
public:
  GLConsole();

  void textUpdated(const std::string& newText) override;
  void addConsoleTab();

  virtual QSize sizeHint() const override;

private:
  QTextEdit* consoleTextEdit;
};

#endif
