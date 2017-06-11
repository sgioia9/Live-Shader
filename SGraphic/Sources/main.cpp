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

  /*
  GLConsole console;
  Logger& logger = Logger::get();
  logger.logLine("hola");
  logger.logLine("chao");
  logger.logLine("xd");
  logger.notify();
  */

  return app.exec();
}
