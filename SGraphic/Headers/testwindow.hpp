#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "camerawindow.hpp"
#include "shader.hpp"
#include "model.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <iostream>

class TestWindow : public CameraWindow {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  std::unique_ptr<Core::Shader> shader;
  std::unique_ptr<Core::Model> geomodel;
  std::unique_ptr<glm::mat4> model;
  std::unique_ptr<glm::mat4> view;
  std::unique_ptr<glm::mat4> projection;

  unsigned char* image;
};

#endif
