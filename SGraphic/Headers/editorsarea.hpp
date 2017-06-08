#ifndef EDITORSAREA_HPP
#define EDITORSAREA_HPP

#include <QWidget>

class EditorsTabs;
class MainFrame;

class EditorsArea : public QWidget {
  Q_OBJECT
public:
  EditorsArea(QWidget* parent = 0);

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;
private:
  EditorsTabs* _tabs;

  friend MainFrame;
};

#endif
