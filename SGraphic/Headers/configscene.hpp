#ifndef CONFIGSCENE_HPP
#define CONFIGSCENE_HPP

#include "scene.hpp"
#include "configuration.hpp"

#include <string>

class ConfigScene : public Scene {
public:
  ConfigScene(const ModelInfo&);
  virtual ~ConfigScene();

  virtual void draw() override;
private:
  void build();
  std::string _vertexSource;
  std::string _fragmentSource;
  std::string _modelPath;
};

#endif
