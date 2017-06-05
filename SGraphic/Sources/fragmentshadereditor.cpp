#include "util.hpp"
#include "fragmentshadereditor.hpp"

FragmentShaderEditor* FragmentShaderEditor::_instance = nullptr;

FragmentShaderEditor* FragmentShaderEditor::get() {
  if (!_instance) _instance = new FragmentShaderEditor();
  return _instance;
}

FragmentShaderEditor::FragmentShaderEditor() { 
  _textEdit->setText(
     QString::fromStdString( 
       Util::readShader("simple.frag")));
}
