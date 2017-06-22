#include "shaderhighlighter.hpp"

ShaderHightlighter::ShaderHightlighter(QTextDocument* parent)
  : QSyntaxHighlighter(parent) {
  HighlightRule rule;  

  keywordFormat.setFontWeight(QFont::Bold);
  keywordFormat.setForeground(Qt::darkBlue);
  QStringList keywordPatterns;
  keywordPatterns << "\\buniform\\b" << "\\blayout\\b" << "\\bin\\b"
                  << "\\bout\\b";

  foreach (const QString& pattern, keywordPatterns) {
    rule.pattern = QRegularExpression(pattern);
    rule.format = keywordFormat;
    rules.append(rule);
  }
}

void ShaderHightlighter::highlightBlock(const QString& text) {
  foreach (const HighlightRule& rule, rules) {
    QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
    while (matchIterator.hasNext()) {
      QRegularExpressionMatch match = matchIterator.next();
      setFormat(match.capturedStart(), match.capturedEnd(), rule.format);
    }
  }
}
