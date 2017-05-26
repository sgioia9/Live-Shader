#include <QGuiApplication>
#include "testwindow.hpp"

//static GLFWwindow* create_window(const int width, const int height);
//static void renderLoop(GLFWwindow*, const Core::Shader& shader);

int main(int argc, char** argv) {
  QGuiApplication app(argc, argv);

  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  format.setVersion(4, 3);

  TestWindow window;
  window.setFormat(format);
  window.resize(QSize(800, 600));
  window.show();

  return app.exec();
}
/*

int main() {
  glfwInit();

  auto mWindow = create_window(mWidth, mHeight);
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

  const Core::Shader shader = Core::ShaderBuilder::createBuilder() 
                                ->addSource("simple.vert")
                                ->addSource("simple.frag")
                                ->build();

  renderLoop(mWindow, shader);

  glfwTerminate();
  return 0;
}

void renderLoop(GLFWwindow* window, const Core::Shader& shader) {

  GLfloat vertices[] = 
  {
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
  };

  GLuint indices[] =
  {
   0, 1, 3,
   1, 2, 3 
  };

  GLuint VBO, VAO, EBO;
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

	shader.use();
	while (glfwWindowShouldClose(window) == false) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(VAO);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}   
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

GLFWwindow* create_window(const int width, const int height) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	return glfwCreateWindow(width, height, "OpenGL", nullptr, nullptr);
}
*/
