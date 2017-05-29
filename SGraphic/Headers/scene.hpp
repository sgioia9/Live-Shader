#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include "shader.hpp"
#include "worldobject.hpp"
#include "fpcamera.hpp"
#include "camcontroller.hpp"

class Scene {
public:
  Scene();
  void attachController(CamController& conntroller);

  virtual void draw() = 0;
  
protected:
  std::unique_ptr<Core::Shader> _shader;
  std::unique_ptr<Core::WorldObject> _object;
  std::shared_ptr<Core::FPCamera> _camera;
};

class NullScene : public Scene { 
public:
  void draw() override { }
};


#endif
