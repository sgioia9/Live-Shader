#include <QApplication>
#include "testwindow.hpp"
#include "mainframe.hpp"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(format);

  /*
  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  format.setVersion(4, 3);
  TestWindow window;
  window.setFormat(format);
  window.resize(QSize(800, 600));
  window.show();
  */

  MainFrame mainFrame;
  mainFrame.show();

  return app.exec();
}
