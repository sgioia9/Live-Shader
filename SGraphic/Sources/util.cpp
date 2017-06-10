#include <iostream>
#include <sstream>

#include "util.hpp"

namespace Util {
  static const std::string SHADER_PATH = "SGraphic/Resources/Shaders/";

  std::string readShader(const std::string& filename) {
    return readFile(SHADER_PATH + filename);
  }

  std::string readFile(const std::string& path) {
    std::ifstream file;
    file.open(path);
    if (!file.is_open()) {
      throw "Could not open file" + path + "\n";
    }
    std::stringstream sstream;
    sstream << file.rdbuf();
    return sstream.str();
  }
}
