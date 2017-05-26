#ifndef TESTRENDERER_HPP
#define TESTRENDERER_HPP

#include "gladrenderer.hpp" 

class TestRenderer : public GladRenderer {  
public:
  TestRenderer() { }
  virtual void initGL() override;
  virtual void paintGL() override;
  virtual void teardownGL() override;

  GLuint VBO, VAO, EBO;

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


};

#endif // TESTRENDERER_HPP
