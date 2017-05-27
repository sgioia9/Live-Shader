#include <fstream>
#include <iostream>
#include "SOIL.h"

#include "resourceloader.hpp"

namespace Core {
#ifdef DEVELOP
  const std::string ResourceLoader::IMAGES_PATH = 
    "/home/stefano/Repositories/SGraphic/SGraphic/Textures/";
#else
  const std::string ResourceLoader::IMAGES_PATH = "";
#endif

  ImageResource ResourceLoader::loadImage(const std::string& path) {
    ImageResource result;
    const std::string full_path = IMAGES_PATH + path;
    int iwidth;
    int iheight;
    unsigned char* image = SOIL_load_image(full_path.c_str(), &iwidth, &iheight, 0, SOIL_LOAD_RGB);
    std::cerr << "Loaded image = (" << iwidth << " x " << iheight << ")" << std::endl;
    result.data = image;
    result.width = iwidth;
    result.height = iheight;
    return result;
  }

  GLuint ResourceLoader::generateTextureFromFile(const std::string& path) {
    GLuint id;
    glGenTextures(1, &id);
    ImageResource soilImage = loadImage(path);

    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(
        GL_TEXTURE_2D, 
        0, 
        GL_RGB, 
        soilImage.width, 
        soilImage.height, 
        0, 
        GL_RGB, 
        GL_UNSIGNED_BYTE, 
        soilImage.data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    freeImageResource(soilImage);
    return id;
  }

  void ResourceLoader::freeImageResource(ImageResource& resource) {
    SOIL_free_image_data(resource.data);
  }
}
