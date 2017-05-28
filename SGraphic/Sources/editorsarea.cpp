#include <QSize>

#include "editorsarea.hpp"

EditorsArea::EditorsArea() {}

QSize EditorsArea::sizeHint() const {
  return QSize(400, 300);
}

