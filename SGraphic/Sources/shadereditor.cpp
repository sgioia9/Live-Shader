#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "shaderhighlighter.hpp"
#include "shadereditor.hpp"

ShaderEditor::ShaderEditor() { 
  _textEdit = new QTextEdit();  

  QFont font;
  font.setFamily("Courier");
  font.setFixedPitch(true);
  font.setPointSize(11);
  _textEdit->setFont(font);

  _highlighter = new ShaderHightlighter(_textEdit->document());

  QVBoxLayout* mainLayout = new QVBoxLayout();
  mainLayout->addWidget(_textEdit);
  setLayout(mainLayout);
}

std::string ShaderEditor::getText() {
  return _textEdit->toPlainText().toStdString();
}

void ShaderEditor::setText(const std::string& text) {
  _textEdit->setText(QString::fromStdString(text));
}
