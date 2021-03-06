#ifndef LOGGERLISTENER_HPP
#define LOGGERLISTENER_HPP

#include <string>
#include <sstream>
#include <memory>

class Logger;

class LoggerListener {
public:
  void subscribeTo(Logger& logger);
  virtual void textUpdated(const std::string&) = 0;
};

#endif
