#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "oglwindow.hpp"
#include <QOpenGLFunctions>

#include "shader.hpp"
#include <memory>

class TestWindow : public OglWindow {
public:
  virtual void initializeGL() override;
  virtual void paintGL() override;

  std::unique_ptr<Core::Shader> shader;

  GLfloat vertices[12] = 
  {
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
  };

  GLuint indices[6] =
  {
   0, 1, 3,
   1, 2, 3 
  };

  GLuint VBO, VAO, EBO;
};

#endif
