#include <QApplication>
#include <QSurfaceFormat>
#include "mainframe.hpp"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(format);

  MainFrame mainFrame;
  mainFrame.show();

  return app.exec();
}
