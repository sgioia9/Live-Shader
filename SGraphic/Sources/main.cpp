#include <QApplication>
#include <QSurfaceFormat>
#include "mainframe.hpp"



#include "glconsole.hpp"
#include "logger.hpp"
#include <memory>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  /*
  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(format);

  MainFrame mainFrame;
  mainFrame.show();
  */

  std::shared_ptr<Logger> logger = std::make_shared<Logger>();
  GLConsole console(logger);
  logger->logLine("hola");
  logger->logLine("chao");
  logger->logLine("xd");
  logger->notify();

  return app.exec();
}
