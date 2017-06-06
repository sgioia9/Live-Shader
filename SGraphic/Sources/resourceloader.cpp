#include <fstream>
#include <iostream>
#include "SOIL.h"

#include "scenewidget.hpp"
#include "resourceloader.hpp"
#include "logger.hpp"

namespace Core {
  ResourceLoader::ResourceLoader() { gl = SceneWidget::get(); }

  ResourceLoader& ResourceLoader::get() {
    static ResourceLoader instance;
    return instance;
  }

  ImageResource ResourceLoader::loadImage(const std::string& full_path) {
    ImageResource result;
//    std::cerr << "Trying to load image: " << full_path << std::endl;
    int iwidth;
    int iheight;
    unsigned char* image = SOIL_load_image(full_path.c_str(), &iwidth, &iheight, 0, SOIL_LOAD_RGB);
    if (!image) {
      Logger::get().logLine("Could not load image: " + full_path);
      exit(1);
    }
    //Logger::get().logLine("Loaded image = (" + std::to_string(iwidth) + " x " + std::to_string(iheight) + ")");
 //   std::cerr << "Loaded image = (" << std::to_string(iwidth) << " x " << std::to_string(iheight) << ")\n";
    result.data = image;
    result.width = iwidth;
    result.height = iheight;
    return result;
  }

  ImageResource ResourceLoader::loadImage(const std::string& directory, const std::string& name) {
    return loadImage(directory + "/" + name);
  }

  GLuint ResourceLoader::generateTextureFromFile(const std::string& full_path) {
    GLuint id;
    gl->glGenTextures(1, &id);
    ImageResource soilImage = loadImage(full_path);

    gl->glBindTexture(GL_TEXTURE_2D, id);
    gl->glTexImage2D(
        GL_TEXTURE_2D, 
        0, 
        GL_RGB, 
        soilImage.width, 
        soilImage.height, 
        0, 
        GL_RGB, 
        GL_UNSIGNED_BYTE, 
        soilImage.data);
    gl->glGenerateMipmap(GL_TEXTURE_2D);

    gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    gl->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gl->glBindTexture(GL_TEXTURE_2D, 0);
    
    freeImageResource(soilImage);
    return id;
  }

  GLuint ResourceLoader::generateTextureFromFile(
      const std::string& directory, const std::string& name) {
    return generateTextureFromFile(directory + "/" +  name);
  }

  void ResourceLoader::freeImageResource(ImageResource& resource) {
    SOIL_free_image_data(resource.data);
  }
}
