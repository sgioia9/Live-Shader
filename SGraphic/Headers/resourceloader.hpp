#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <memory>

namespace Core {

struct ImageResource {
  unsigned char* data;
  int width;
  int height;
};

class ResourceLoader {
public:
  /* must call freeImageResource(..) after use */
  static ImageResource loadImage(const std::string& path);
  static void freeImageResource(ImageResource& resource);
  static const std::string IMAGES_PATH;
};
}

#endif
