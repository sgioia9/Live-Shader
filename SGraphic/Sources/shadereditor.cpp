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

  QHBoxLayout* buttonsLayout = new QHBoxLayout();
  buttonsLayout->addWidget(new QPushButton(tr("Load ...")));
  buttonsLayout->addWidget(new QPushButton(tr("Save as ...")));
  buttonsLayout->setMargin(0);

  QWidget* buttonsWidget = new QWidget();
  buttonsWidget->setLayout(buttonsLayout);

  mainLayout->addWidget(_textEdit);
  mainLayout->addWidget(buttonsWidget);
  setLayout(mainLayout);
}

std::string ShaderEditor::getText() {
  return _textEdit->toPlainText().toStdString();
}

