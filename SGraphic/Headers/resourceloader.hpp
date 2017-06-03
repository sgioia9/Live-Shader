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
  ImageResource loadImage(const std::string& full_path);
  ImageResource loadImage(const std::string& directory, const std::string& name);
  void freeImageResource(ImageResource& resource);

  /* returns the tex id */
  GLuint generateTextureFromFile(const std::string& path);
  GLuint generateTextureFromFile(const std::string& directory, const std::string& name);

  std::string getShaderSource(const std::string& filename);

  static const std::string SHADERS_PATH;
};
}

#endif
