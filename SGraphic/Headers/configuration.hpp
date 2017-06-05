#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

struct ModelInfo;

class Configuration {
public:
  static Configuration& get();

  ModelInfo getModelInfo();

  void operator=(const Configuration&) = delete;
  Configuration(const Configuration&) = delete;

  void setPathToModel(const std::string& newPath);

private:
  Configuration();

  std::string pathToModel;
};

struct ModelInfo {
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
  std::string pathToModel;
};


#endif
