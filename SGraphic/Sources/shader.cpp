#include "shader.hpp"

#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>


/** Shader **/

void Shader::use() {
  std::cerr << "Using program " << _program << std::endl;
}

/** ShaderBuilder **/

using BuilderPtr = std::shared_ptr<ShaderBuilder>;

BuilderPtr ShaderBuilder::createBuilder() {
  BuilderPtr ptr = std::make_shared<ShaderBuilder>();
  ptr->thisPtr = ptr;
  return ptr;
}

BuilderPtr ShaderBuilder::addSource(const std::string& path) {
  thisPtr->sources.push_back(path);
  return thisPtr;
}

Shader ShaderBuilder::build() {
  GLuint program = glCreateProgram();
  std::vector<int> shaderIds;
  shaderIds.reserve(sources.size());
  for (const auto& shaderFile : sources) {
    GLuint shader = ShaderBuilder::buildSpecificShader(shaderFile);
    // TODO: verificar que shader se pudo compilar
    glAttachShader(program, shader);
    shaderIds.push_back(shader);
  }
  glLinkProgram(program);
  for (const GLuint id : shaderIds) {
    // since shader is already linked, delete them
    glDeleteShader(id);
  }

  Shader shaderObject;
  shaderObject._program = program;
  return shaderObject;
}

GLuint ShaderBuilder::buildSpecificShader(const std::string& path) {
  std::ifstream fstream;
  std::stringstream sstream;
#ifdef PROJECT_SHADERS_DIR
  fstream.open(PROJECT_SHADERS_DIR + path);
#else
  fstream.open(path);
#endif
  const GLchar* code;
  sstream << fstream.rdbuf();
  code = sstream.str().c_str();

  GLuint shaderHandle;
  auto dotIndex = path.rfind(".");
  auto extension = path.substr(dotIndex + 1);
  if (extension == "vert") {
    shaderHandle = glCreateShader(GL_VERTEX_SHADER); 
  } else if (extension == "frag") {
    shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
  } else {
    // TODO: Find out what the shader is
    return -1;
  }
  glShaderSource(shaderHandle, 1, &code, NULL);
  glCompileShader(shaderHandle);
  return shaderHandle;
}
