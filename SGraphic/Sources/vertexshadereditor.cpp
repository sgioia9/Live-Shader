#include "util.hpp"
#include "logger.hpp"
#include "vertexshadereditor.hpp"
#include <iostream>

VertexShaderEditor* VertexShaderEditor::_instance = nullptr;

VertexShaderEditor* VertexShaderEditor::get() {
  if (!_instance) _instance = new VertexShaderEditor();
  return _instance;
}

VertexShaderEditor::VertexShaderEditor() {
  try {
    _textEdit->setText(
       QString::fromStdString( 
         Util::readShader("simple.vert")));
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
}

void VertexShaderEditor::load() {
  std::cerr << "vertex load" << std::endl;
}
