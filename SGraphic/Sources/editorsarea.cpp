#include <QSize>
#include <QVBoxLayout>
#include <QPushButton>
#include "editorstabs.hpp"

#include "editorsarea.hpp"

EditorsArea::EditorsArea(QWidget* parent): QWidget(parent) {
  QVBoxLayout* mainLayout = new QVBoxLayout();
  _tabs = new EditorsTabs();
  mainLayout->addWidget(_tabs);
  mainLayout->setMargin(0);
  setLayout(mainLayout);
}

QSize EditorsArea::minimumSizeHint() const {
  return QSize(566, 600);
}

QSize EditorsArea::sizeHint() const {
  return QSize(566, 600);
}


