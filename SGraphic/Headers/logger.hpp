#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <vector>
#include <sstream>

class LoggerListener;

class Logger {
public:
  void newSubscriber(LoggerListener* subscriber);
  void notify();
  void log(const std::string& message);
  void logLine(const std::string& message);

private:
  std::vector<LoggerListener*> _subscribers;
  std::stringstream _storedText;
};


#endif
