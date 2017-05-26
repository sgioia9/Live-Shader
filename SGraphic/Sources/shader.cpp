#include "shader.hpp"

#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

/** Shader **/

namespace Core {

#ifdef DEVELOP
#ifdef __MACH__
const std::string ShaderBuilder::SHADER_DIR = "/Users/sgioia/Repositories/SGraphic/SGraphic/Shaders/";
#else
const std::string ShaderBuilder::SHADER_DIR = "/home/stefano/Repositories/SGraphic/SGraphic/Shaders/";
#endif
#endif

/** Shader **/

void Shader::use() {
  std::cerr << "Using program " << _program << std::endl;
  glUseProgram(_program);
}

void Shader::uniformMatrix(GLint location, const glm::mat4& matrix) { 
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::uniformMatrix(const std::string& name, const glm::mat4& matrix) {
  glUniformMatrix4fv(getLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

GLint Shader::getLocation(const std::string& name) {
  glGetUniformLocation(_program, name.c_str());
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
#ifdef DEVELOP
  std::cerr << SHADER_DIR + path << std::endl;
  fstream.open(SHADER_DIR + path);
#else
  std::cerr << path << std::endl;
  fstream.open(path);
#endif

  if (!fstream.is_open()) {
    throw "Could not open file: " + path + "\n";
  }
  sstream << fstream.rdbuf();
  auto shaderSource = sstream.str();
  const GLchar* code = shaderSource.c_str();

  GLuint shaderHandle;
  auto dotIndex = path.rfind(".");
  auto extension = path.substr(dotIndex + 1);
  if (extension == "vert") {
    shaderHandle = glCreateShader(GL_VERTEX_SHADER); 
  } else if (extension == "frag") {
    shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
  } else {
    throw "Uknown shader extension for " + path + "\n";
  }
  glShaderSource(shaderHandle, 1, &code, NULL);
  glCompileShader(shaderHandle);
  GLint success;
  glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLchar infoLog[512];
    glGetShaderInfoLog(shaderHandle, 512, NULL, infoLog);
    std::cerr << "Shader compilation failed" << std::endl;
    std::cerr << infoLog << std::endl;
    throw "Could not compile shader " + path +
          "\nLog: " + std::string(infoLog) + "\n";
  }
  return shaderHandle;
}

}
