#include "shader.hpp"

#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

/** Shader **/

namespace Core {

/** Shader **/

void Shader::use() {
  glUseProgram(_program);
}

void Shader::uniformMatrix(GLint location, const glm::mat4& matrix) { 
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::uniformMatrix(const std::string& name, const glm::mat4& matrix) {
  glUniformMatrix4fv(getLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::uniformInt(const std::string& name, GLint value) { 
  glUniform1i(getLocation(name), value);
}

void Shader::uniformInt(GLint location, GLint value) { 
  glUniform1i(location, value);
}

void Shader::uniformFloat(GLint location, GLfloat value) {
  glUniform1f(location, value);
}

void Shader::uniformFloat(const std::string& name, GLfloat value) {
  glUniform1f(getLocation(name), value);
}

GLint Shader::getLocation(const std::string& name) {
  return glGetUniformLocation(_program, name.c_str());
}

/** ShaderBuilder **/

using BuilderPtr = std::shared_ptr<ShaderBuilder>;

BuilderPtr ShaderBuilder::createBuilder() {
  BuilderPtr ptr = std::make_shared<ShaderBuilder>();
  ptr->thisPtr = ptr;
  return ptr;
}

BuilderPtr ShaderBuilder::addVertexShaderSource(const std::string& source) {
  vertexShaderSource = source;
  return thisPtr;
}

BuilderPtr ShaderBuilder::addFragmentShaderSource(const std::string& source) {
  fragmentShaderSource = source;
  return thisPtr;
}

Shader ShaderBuilder::build() {
  GLuint program = glCreateProgram();
  std::vector<int> shaderIds;
  std::cerr << "building vert shader with source:\n";
  std::cerr << vertexShaderSource << std::endl;
  GLuint vertShader = ShaderBuilder::buildShaderWithSource(vertexShaderSource, GL_VERTEX_SHADER);
  std::cerr << "building fragment shader with source:\n";
  std::cerr << fragmentShaderSource << std::endl;
  GLuint fragmentShader = ShaderBuilder::buildShaderWithSource(fragmentShaderSource, GL_FRAGMENT_SHADER);
  glAttachShader(program, vertShader);
  glAttachShader(program, fragmentShader);
  shaderIds.push_back(vertShader);
  shaderIds.push_back(fragmentShader);;
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
  fstream.open(path);

  if (!fstream.is_open()) {
    throw "Could not open file: " + path + "\n";
  }
  sstream << fstream.rdbuf();
  auto shaderSource = sstream.str();

  auto dotIndex = path.rfind(".");
  auto extension = path.substr(dotIndex + 1);

  GLuint shaderHandle;
  if (extension == "vert") {
    shaderHandle = buildShaderWithSource(shaderSource, GL_VERTEX_SHADER);
  } else if (extension == "frag") {
    shaderHandle = buildShaderWithSource(shaderSource, GL_FRAGMENT_SHADER);
  } else {
    throw "Uknown shader extension for " + path + "\n";
  }
  return shaderHandle;
}

GLuint ShaderBuilder::buildShaderWithSource(const std::string& source, GLenum shaderType) {
  GLuint shaderHandle = glCreateShader(shaderType);

  std::string sourceCpy = source;
  const GLchar* code = sourceCpy.c_str();

  glShaderSource(shaderHandle, 1, &code, NULL);
  glCompileShader(shaderHandle);
  GLint success;
  glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLchar infoLog[512];
    glGetShaderInfoLog(shaderHandle, 512, NULL, infoLog);
    std::cerr << "Shader compilation failed" << std::endl;
    std::cerr << infoLog << std::endl;
    throw "Could not compile shader " + source +
      "\nLog: " + std::string(infoLog) + "\n";
  } 
  return shaderHandle;
}

}
