#ifndef GLCONSOLE_HPP
#define GLCONSOLE_HPP

#include <QTabWidget>
#include <memory>
#include "loggerlistener.hpp"

class Logger;

class GLConsole : public QTabWidget, public LoggerListener {
  Q_OBJECT
public:
  GLConsole();

  void textUpdated(const std::string& newText);
  void addNewTab(const QString& name);
};

#endif
