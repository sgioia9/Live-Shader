#ifndef SHADEREDITOR_HPP
#define SHADEREDITOR_HPP

#include <QWidget>

class QTextEdit;

class ShaderEditor : public QWidget {
public:
  ShaderEditor();

private:
  QTextEdit* textEdit;
};

#endif
