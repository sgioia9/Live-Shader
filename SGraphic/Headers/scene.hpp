#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <iostream>
#include "shader.hpp"
#include "worldobject.hpp"
#include "fpcamera.hpp"
#include "camcontroller.hpp"

class Scene {
public:
  Scene();
  void attachController(std::shared_ptr<CamController> conntroller);

  virtual void draw() = 0;

  virtual ~Scene() { }
  
protected:
  std::unique_ptr<Core::Shader> _shader;
  std::unique_ptr<Core::WorldObject> _object;
  std::shared_ptr<Core::FPCamera> _camera;
};

class NullScene : public Scene { 
public:
  void draw() override { }
  ~NullScene() { }
};

class DebugScene : public Scene, public QOpenGLExtraFunctions {
public: 
  virtual ~DebugScene() { }
  DebugScene() {
    initializeOpenGLFunctions();
	  
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);    

    glGenBuffers(1, &vbo); 
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

      glBindBuffer(GL_ARRAY_BUFFER, vbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

      glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
  }

  void draw() override {
    glBindVertexArray(vao); 
      glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);;
  }
 	const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"; 
	const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

  GLuint shaderProgram;  
  GLuint vao;
  GLuint vbo;
  GLfloat vertices[9] =
  {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };
};


#endif
