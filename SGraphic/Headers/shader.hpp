#ifndef SHADER_HPP
#define SHADER_HPP

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>
#include <QOpenGLFunctions>

namespace Core {

class ShaderBuilder;

class Shader : public QOpenGLFunctions {

public:
  /* Enables the shader in the OpenGL context*/
  void use();
  void uniformMatrix(GLint location, const glm::mat4& matrix);
  void uniformMatrix(const std::string& name, const glm::mat4& matrix);
  void uniformFloat(const std::string& name, GLfloat value);
  GLint getLocation(const std::string& name);
  
  GLuint _program;

private:
  Shader() { initializeOpenGLFunctions(); }

  friend ShaderBuilder;
};

class ShaderBuilder : public QOpenGLFunctions {
using BuilderPtr = std::shared_ptr<ShaderBuilder>;

public:
  ShaderBuilder() { initializeOpenGLFunctions(); }

  static BuilderPtr createBuilder();

  BuilderPtr addSource(const std::string& path);

  Shader build();

#ifdef DEVELOP
  static const std::string SHADER_DIR;
#endif

private:
  GLuint buildSpecificShader(const std::string& path);
  

  std::vector<std::string> sources;
  BuilderPtr thisPtr;
};
}
#endif // SHADER_HPP
