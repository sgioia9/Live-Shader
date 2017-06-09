#ifndef SHADEREDITOR_HPP
#define SHADEREDITOR_HPP

#include <QWidget>

class QTextEdit;
class ShaderHightlighter;

class ShaderEditor : public QWidget {
public:
  ShaderEditor();
  
  std::string getText();

protected:
  QTextEdit* _textEdit;
  ShaderHightlighter* _highlighter;
};

#endif
