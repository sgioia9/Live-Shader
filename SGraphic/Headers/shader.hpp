#ifndef SHADER_HPP
#define SHADER_HPP

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>
#include <QOpenGLFunctions>

namespace Core {

class ShaderBuilder;

class Shader {

public:
  /* Enables the shader in the OpenGL context*/
  void use();
  void uniformMatrix(GLint location, const glm::mat4& matrix);
  void uniformMatrix(const std::string& name, const glm::mat4& matrix);
  void uniformInt(const std::string& name, GLint value);
  void uniformInt(GLint location, GLint value);
  void uniformFloat(GLint location, GLfloat value);
  void uniformFloat(const std::string& name, GLfloat value);
  void uniformVec3(GLint location, const glm::vec3& vec);
  void uniformVec3(const std::string& name, const glm::vec3& vec);

  GLint getLocation(const std::string& name);

  GLuint _program;

private:
  Shader();

  QOpenGLExtraFunctions* gl;

  friend ShaderBuilder;
};

class ShaderBuilder {
using BuilderPtr = std::shared_ptr<ShaderBuilder>;

public:
  ShaderBuilder();

  static BuilderPtr createBuilder();

  BuilderPtr addVertexShaderSource(const std::string& source);
  BuilderPtr addFragmentShaderSource(const std::string& source);

  Shader build();

private:
  GLuint buildSpecificShader(const std::string& path);
  GLuint buildShaderWithSource(const std::string& source, GLenum shaderType);
  QOpenGLExtraFunctions* gl;

  std::string vertexShaderSource;
  std::string fragmentShaderSource;
  BuilderPtr thisPtr;
};
}
#endif // SHADER_HPP
