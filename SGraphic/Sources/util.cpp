#include <iostream>
#include <sstream>

#include "util.hpp"

namespace Util {
  static const std::string SHADER_PATH = "SGraphic/Resources/Shaders/";

  std::string readShader(const std::string& filename) {
    std::ifstream file;
    std::string fullPath = SHADER_PATH + filename;
    file.open(fullPath);
    if (!file.is_open()) {
      throw "Could not open file" + filename + "\n";
    }
    std::stringstream sstream;
    sstream << file.rdbuf();
    return sstream.str();
  }
}
