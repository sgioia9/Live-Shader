#include "util.hpp"
#include "logger.hpp"
#include "fragmentshadereditor.hpp"
#include "scenewidget.hpp"
#include <iostream>
#include <QTextEdit>

FragmentShaderEditor* FragmentShaderEditor::_instance = nullptr;

FragmentShaderEditor* FragmentShaderEditor::get() {
  if (!_instance) _instance = new FragmentShaderEditor();
  return _instance;
}

FragmentShaderEditor::FragmentShaderEditor() { 
  try {
    setText(Util::readShader("simple.frag"));
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
}

void FragmentShaderEditor::load() {
  try {
    QString selectedFile = 
      SceneWidget::get()->browseFileDialog(
          tr("Load fragment shader"), "", tr("Fragment shaders (*.frag)"));
    setText(Util::readFile(selectedFile.toStdString()));
    if (selectedFile.isEmpty()) return;
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
}
