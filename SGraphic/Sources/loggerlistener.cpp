#include "logger.hpp"
#include <memory>
#include "loggerlistener.hpp"

void LoggerListener::subscribeTo(Logger& logger) {
  logger.newSubscriber(this);
}
