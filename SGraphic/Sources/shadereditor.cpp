#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "shadereditor.hpp"

ShaderEditor::ShaderEditor() { 
  _textEdit = new QTextEdit();  
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

