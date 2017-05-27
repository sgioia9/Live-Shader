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



  void ResourceLoader::freeImageResource(ImageResource& resource) {
    SOIL_free_image_data(resource.data);
  }
}
