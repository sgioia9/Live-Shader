#ifndef CONFIGSCENE_HPP
#define CONFIGSCENE_HPP

#include "scene.hpp"

#include <string>

class ConfigScene : public Scene {
public:
  ConfigScene() {}

  void setVertexShader(const std::string& path);
  void setFragmentShader(const std::string& path);
  void setModel(const std::string& path);

  void build();
  virtual void draw() override;
private:
  std::string vertexPath;
  std::string fragmentPath;
  std::string modelPath;
};

#endif
