#include "util.hpp"
#include "vertexshadereditor.hpp"

VertexShaderEditor* VertexShaderEditor::_instance = nullptr;

VertexShaderEditor* VertexShaderEditor::get() {
  if (!_instance) _instance = new VertexShaderEditor();
  return _instance;
}

VertexShaderEditor::VertexShaderEditor() {
  _textEdit->setText(
     QString::fromStdString( 
       Util::readShader("simple.vert")));
}
