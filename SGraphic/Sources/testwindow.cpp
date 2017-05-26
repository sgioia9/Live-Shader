#include <iostream>
#include "SOIL.h"

#include "testwindow.hpp"


void TestWindow::initializeGL() {
  OglWindow::initializeGL();

  shader.reset(new Core::Shader(Core::ShaderBuilder::createBuilder() 
                                ->addSource("simple.vert")
                                ->addSource("simple.frag")
                                ->build()));
  int iwidth, iheight;
#ifdef DEVELOP
  const std::string IMG_DIR = "/home/stefano/Repositories/SGraphic/SGraphic/Textures/";
#else
  const std::string IMG_DIR = "";
#endif
  const std::string full_path = IMG_DIR + "container.jpg";
  const char* image_path = full_path.c_str();
  image = SOIL_load_image(image_path, &iwidth, &iheight, 0, SOIL_LOAD_RGB); 
  std::cerr << "Loaded image = (" << iwidth << " x " << iheight << ")" << std::endl;

  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  shader->use();
}

void TestWindow::teardownGL() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  SOIL_free_image_data(image);
}

void TestWindow::paintGL() {
  glClearColor(0.7f, 0.2f, 0.5f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}

