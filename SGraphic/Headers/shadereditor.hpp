#ifndef SHADEREDITOR_HPP
#define SHADEREDITOR_HPP

#include <QWidget>

class QTextEdit;
class ShaderHightlighter;

class ShaderEditor : public QWidget {
  Q_OBJECT
public:
  ShaderEditor();
  
  std::string getText();

protected slots:
  virtual void onLoadButtonClick() = 0;
  virtual void onSaveButtonClick() = 0;

protected:
  QTextEdit* _textEdit;
  ShaderHightlighter* _highlighter;

  void setText(const std::string& text);
  virtual void save() = 0;
  virtual void load() = 0;
};

#endif
