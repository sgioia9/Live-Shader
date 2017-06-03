#include "displayedmodellabel.hpp"

const std::string DisplayedModelLabel::prefix = "Currently displayed model: ";

DisplayedModelLabel::DisplayedModelLabel() {
  displayModelName("none");
}

void DisplayedModelLabel::displayModelName(const std::string& name) {
  setText(QString::fromStdString(prefix + name));
}

