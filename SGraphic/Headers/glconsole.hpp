#ifndef GLCONSOLE_HPP
#define GLCONSOLE_HPP

#include <QWidget>
#include <memory>
#include "loggerlistener.hpp"

class Logger;

class GLConsole : public QWidget, public LoggerListener {
public:
  GLConsole(const std::shared_ptr<Logger>& logger);

  void textUpdated(const std::string& newText);

private:
  std::shared_ptr<Logger> _logger;
};

#endif
