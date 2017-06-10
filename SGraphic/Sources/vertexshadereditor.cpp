#include "util.hpp"
#include "logger.hpp"
#include "vertexshadereditor.hpp"
#include "scenewidget.hpp"
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
  try {
    QString selectedFile = 
      SceneWidget::get()->browseFileDialog(
        tr("Load vertex shader"), "", tr("Vertex Shaders (*.vert)"));
    if (selectedFile.isEmpty()) return;
    setText(Util::readFile(selectedFile.toStdString()));
  } catch (const std::string& err) {
    Logger::get().logErrorLine(err);
  }
}

void VertexShaderEditor::save() {
  std::cerr << "vertex save" << std::endl;
}
