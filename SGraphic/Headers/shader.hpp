#ifndef SHADER_HPP
#define SHADER_HPP

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
