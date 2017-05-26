#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "oglwindow.hpp"
#include "shader.hpp"

#include <memory>

class TestWindow : public OglWindow {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  std::unique_ptr<Core::Shader> shader;

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
