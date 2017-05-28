#include <QSize>

#include "editorsarea.hpp"

EditorsArea::EditorsArea() {}

QSize EditorsArea::minimumSizeHint() const {
  return QSize(400, 300);
}

QSize EditorsArea::sizeHint() const {
  return QSize(400, 300);
}


