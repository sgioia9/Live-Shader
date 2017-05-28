#include "logger.hpp"
#include <memory>
#include "loggerlistener.hpp"

void LoggerListener::subscribeTo(std::shared_ptr<Logger> logger) {
  logger->newSubscriber(this);
}
