#ifndef SHADEREDITOR_HPP
#define SHADEREDITOR_HPP

#include <QWidget>
#include <QTextEdit>

class ShaderEditor : public QWidget {
public:
  ShaderEditor();

protected:
  QTextEdit* _textEdit;
};

#endif
