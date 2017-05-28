#include <QSize>
#include <QVBoxLayout>
#include <QPushButton>
#include "editorstabs.hpp"

#include "editorsarea.hpp"

EditorsArea::EditorsArea(QWidget* parent): QWidget(parent) {
  QVBoxLayout* mainLayout = new QVBoxLayout();
  mainLayout->addWidget(new EditorsTabs());
  mainLayout->setMargin(0);
  setLayout(mainLayout);
}

QSize EditorsArea::minimumSizeHint() const {
  return QSize(400, 300);
}

QSize EditorsArea::sizeHint() const {
  return QSize(400, 300);
}


