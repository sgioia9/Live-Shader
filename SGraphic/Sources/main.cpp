// Local Headers
#include <sgraphic.hpp>

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "shader.hpp"

static GLFWwindow* init_glfw_and_create_window(const int width, const int height);

int main() {
  auto mWindow = init_glfw_and_create_window(mWidth, mHeight);

  if (mWindow == nullptr) {
    std::cerr << "Failed to create window.\n";
    return -1;
  }

  glfwMakeContextCurrent(mWindow);
  if (!gladLoadGL()) {
    std::cerr << "Could not load OpenGL.\n";
  } else {
    std::cerr << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
  }
  Shader shader = ShaderBuilder::createBuilder() 
                                ->addSource("simple.vert")
                                ->addSource("simple.frag")
                                ->build();
  shader.use();
  return 0;

  while (glfwWindowShouldClose(mWindow) == false) {
    if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(mWindow, true);

    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mWindow);
    glfwPollEvents();
  }   glfwTerminate();
  return 0;
}

GLFWwindow* init_glfw_and_create_window(const int width, const int height) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  return glfwCreateWindow(width, height, "OpenGL", nullptr, nullptr);
}
