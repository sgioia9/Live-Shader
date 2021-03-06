#ifndef WORLDOBJECT_HPP
#define WORLDOBJECT_HPP

#include <memory>
#include <glm/glm.hpp>
#include "model.hpp"

namespace Core {
class WorldObject {
public:
  WorldObject(
      const std::shared_ptr<Model>& model,
      const glm::mat4& transform);
  
  WorldObject(const std::shared_ptr<Model>& model);

  void scaleDown();
  void scaleUp();
  void rotateYAxis(float speed);
  void rotateXAxis(float speed);

  std::shared_ptr<Model> _model;
  glm::mat4 _transform;
};
}

#endif
