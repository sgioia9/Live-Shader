#include "util.hpp"
#include "fragmentshadereditor.hpp"

FragmentShaderEditor::FragmentShaderEditor() { 
  _textEdit->setText(
     QString::fromStdString( 
       Util::readShader("simple.frag")));
}
