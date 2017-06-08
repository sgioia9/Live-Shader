#include <vector>
#include <iostream>

#include "logger.hpp"
#include "loggerlistener.hpp"

Logger& Logger::get() {
  static Logger instance;
  return instance;
}

void Logger::newSubscriber(LoggerListener* subscriber) {
  _subscribers.push_back(subscriber);
}

void Logger::notify() {
  for (auto it = _subscribers.begin(); it != _subscribers.end(); ++it) {
    LoggerListener* subscriber = *it;
    const std::string text = _storedText.str();
    if (subscriber) {
      subscriber->textUpdated(text);
    } else {
      _subscribers.erase(it);
    }
  }
  _storedText.str(std::string());
  _storedText.clear();
}

void Logger::logLine(const std::string& message) {
  _storedText << message + "\n";
#ifdef DEVELOP
  std::cerr << message << "\n";
#endif
  notify();
}

void Logger::logErrorLine(const std::string& message) {
  _storedText << "ERROR: " << message << "\n";
#ifdef DEVELOP
  std::cerr << "ERROR: " << message << "\n";
#endif
  notify();
}

