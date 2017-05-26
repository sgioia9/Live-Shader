#include <iostream>
#include <cmath>
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "testwindow.hpp"


void TestWindow::initializeGL() {
  OglWindow::initializeGL();

  camera.reset(new Core::FPCamera());
  camera->setPosition(0.0f, 0.0f, 3.0f);
  shader.reset(new Core::Shader(Core::ShaderBuilder::createBuilder() 
                                ->addSource("simple.vert")
                                ->addSource("simple.frag")
                                ->build()));
  model.reset(new glm::mat4());
  view.reset(new glm::mat4());
  projection.reset(new glm::mat4());

  *model = glm::rotate(*model, glm::radians(-55.0f), glm::vec3(0.5f, 1.0f, 0.0f));
  *view = glm::translate(*view, glm::vec3(0.0f, 0.0f, -3.0f));
  *projection = glm::perspective(glm::radians(45.0f), 1.0f * width() / height(), 0.1f, 100.0f);

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

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iwidth, iheight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  glGenerateMipmap(GL_TEXTURE_2D);

  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0);

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  shader->use();
}

void TestWindow::teardownGL() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

void TestWindow::paintGL() {
  OglWindow::paintGL();

  *view = camera->view();

  shader->uniformMatrix("model", *model);
  shader->uniformMatrix("view", *view);
  shader->uniformMatrix("projection", *projection);

  glBindTexture(GL_TEXTURE_2D, texture);
  glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}

void TestWindow::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_A) {
    camera->moveLeft();
  } else if (event->key() == Qt::Key_S) {
    camera->moveBackward();
  } else if (event->key() == Qt::Key_D) {
    camera->moveRight();
  } else if (event->key() == Qt::Key_W) {
    camera->moveForward();
  }
  std::cerr << *camera << std::endl;
}

