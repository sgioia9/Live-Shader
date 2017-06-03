#ifndef DISPLAYEDMODELLABEL_HPP
#define DISPLAYEDMODELLABEL_HPP

#include <QLabel>
#include <string>
class DisplayedModelLabel : public QLabel {
public:
  DisplayedModelLabel();
  void displayModelName(const std::string& name);
private:
  static const std::string prefix;
};

#endif
