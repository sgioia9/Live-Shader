#include "fragmentshadereditor.hpp"
#include "vertexshadereditor.hpp"
#include <iostream>

#include "configuration.hpp"

Configuration::Configuration() { }

Configuration& Configuration::get() {
  static Configuration instance;
  return instance;
}

void Configuration::setPathToModel(const std::string& newPath) {
  pathToModel = newPath;
}

ModelInfo Configuration::getModelInfo() {
  ModelInfo info;
  info.vertexShaderSource = VertexShaderEditor::get()->getText(); 
  info.fragmentShaderSource = FragmentShaderEditor::get()->getText();
  info.pathToModel = pathToModel;
  return info;
}
