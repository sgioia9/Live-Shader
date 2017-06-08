#include "util.hpp"
#include "logger.hpp"
#include "fragmentshadereditor.hpp"
#include <iostream>

FragmentShaderEditor* FragmentShaderEditor::_instance = nullptr;

FragmentShaderEditor* FragmentShaderEditor::get() {
  if (!_instance) _instance = new FragmentShaderEditor();
  return _instance;
}

FragmentShaderEditor::FragmentShaderEditor() { 
  try {
    _textEdit->setText(
       QString::fromStdString( 
         Util::readShader("simple.frag")));
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
}

void FragmentShaderEditor::load() {
  std::cerr << "fragment load" << std::endl;
}
