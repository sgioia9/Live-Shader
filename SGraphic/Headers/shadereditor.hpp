#ifndef SHADEREDITOR_HPP
#define SHADEREDITOR_HPP

#include <QWidget>
#include <QTextEdit>

class ShaderEditor : public QWidget {
public:
  ShaderEditor();
  
  std::string getText();

protected:
  QTextEdit* _textEdit;
};

#endif
