#ifndef CONFIGSCENE_HPP
#define CONFIGSCENE_HPP

#include "scene.hpp"

#include <string>

class ConfigScene : public Scene {
public:
  ConfigScene() {}

  void setVertexShaderSource(const std::string& source);
  void setFragmentShaderSource(const std::string& source);
  void setModel(const std::string& path);

  void build();
  virtual void draw() override;
private:
  std::string _vertexSource;
  std::string _fragmentSource;
  std::string _modelPath;
};

#endif
