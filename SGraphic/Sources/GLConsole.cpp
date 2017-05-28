
#include <memory>
#include <iostream>

#include "glconsole.hpp"

GLConsole::GLConsole(const std::shared_ptr<Logger>& logger) 
  : _logger(logger) { 
  subscribeTo(_logger);  
}

void GLConsole::textUpdated(const std::string& newText) {
  std::cerr << newText;
}
