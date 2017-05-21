#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <vector>
#include <memory>

#include <glad/glad.h>

class ShaderBuilder;

class Shader {

public:
  /* Enables the shader in the OpenGL context*/
  void use();
  GLuint _program;

private:
  Shader() { }

  friend ShaderBuilder;
};

class ShaderBuilder {
using BuilderPtr = std::shared_ptr<ShaderBuilder>;

public:
  ShaderBuilder() { }

  static BuilderPtr createBuilder();

  BuilderPtr addSource(const std::string& path);

  Shader build();

  static const std::string SHADER_DIR;

private:
  static GLuint buildSpecificShader(const std::string& path);
  

  std::vector<std::string> sources;
  BuilderPtr thisPtr;
};
#endif // SHADER_HPP
