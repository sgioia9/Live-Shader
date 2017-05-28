#ifndef EDITORSAREA_HPP
#define EDITORSAREA_HPP

#include <QWidget>

class EditorsArea : public QWidget {
  Q_OBJECT
public:
  EditorsArea(QWidget* parent = 0);

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;
};

#endif
