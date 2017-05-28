#ifndef EDITORSAREA_HPP
#define EDITORSAREA_HPP

#include <QWidget>

class EditorsArea : public QWidget {
  Q_OBJECT
public:
  EditorsArea();

  QSize sizeHint() const override;
};

#endif
