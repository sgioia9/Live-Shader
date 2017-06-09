#ifndef SHADERHIGHLIGHTER_HPP
#define SHADERHIGHLIGHTER_HPP

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>

class QTextCharFormat;

class ShaderHightlighter : public QSyntaxHighlighter {
  Q_OBJECT
public:
  ShaderHightlighter(QTextDocument * parent = 0);

protected:
  virtual void highlightBlock(const QString& text) override;

private:
  struct HighlightRule {
    QRegularExpression pattern;
    QTextCharFormat format;
  };

  QVector<HighlightRule> rules;

  /* formatting for keywords like uniform, vec2, etc */
  QTextCharFormat keywordFormat;

  /* formatting for functions */
  QTextCharFormat functionFormat;

};

#endif
