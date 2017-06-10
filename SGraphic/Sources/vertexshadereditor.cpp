#include "util.hpp"
#include "logger.hpp"
#include "vertexshadereditor.hpp"
#include <iostream>
#include <QTextEdit>

VertexShaderEditor* VertexShaderEditor::_instance = nullptr;

VertexShaderEditor* VertexShaderEditor::get() {
  if (!_instance) _instance = new VertexShaderEditor();
  return _instance;
}

VertexShaderEditor::VertexShaderEditor() {
  try {
    setText(Util::readShader("simple.vert"));
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
}

void VertexShaderEditor::load() {

}
