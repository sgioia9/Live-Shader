#include "util.hpp"
#include "vertexshadereditor.hpp"

VertexShaderEditor::VertexShaderEditor() {
  _textEdit->setText(
     QString::fromStdString( 
       Util::readShader("simple.vert")));
}
