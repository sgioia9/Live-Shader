#include <QTextEdit>
#include <QVBoxLayout>

#include "shadereditor.hpp"

ShaderEditor::ShaderEditor() { 
  textEdit = new QTextEdit();  
  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(textEdit);
  setLayout(layout);
}

