#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <memory>
#include <QOpenGLExtraFunctions>

namespace Core {

struct ImageResource {
  unsigned char* data;
  int width;
  int height;
};

class ResourceLoader : public QOpenGLExtraFunctions {
public:
  ResourceLoader() { initializeOpenGLFunctions(); }

  /* must call freeImageResource(..) after use */
  ImageResource loadImage(const std::string& path);
  void freeImageResource(ImageResource& resource);

  static const std::string IMAGES_PATH;
};
}

#endif
