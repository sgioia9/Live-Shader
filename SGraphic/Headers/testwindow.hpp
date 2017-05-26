#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "oglwindow.hpp"

class TestWindow : public OglWindow {
public:
  virtual void paintGL() override;
};

#endif
