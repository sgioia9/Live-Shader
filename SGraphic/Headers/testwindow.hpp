#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "camerawindow.hpp"
#include "shader.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <iostream>

class TestWindow : public CameraWindow {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  std::unique_ptr<Core::Shader> shader;
  std::unique_ptr<glm::mat4> model;
  std::unique_ptr<glm::mat4> view;
  std::unique_ptr<glm::mat4> projection;

  unsigned char* image;

  GLfloat vertices[20] = 
  {
    // positions        // tex coord
    0.5f, 0.5f, 0.0f,   1.0f, 1.0f, // top right
    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f,  0.0f, 1.0f  // top left
  };

  GLuint indices[6] =
  {
   0, 1, 3,
   1, 2, 3 
  };

  GLuint VBO, VAO, EBO, texture;
};

#endif
