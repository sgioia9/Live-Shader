#include <glm/gtc/matrix_transform.hpp>

#include "worldobject.hpp"

namespace Core {
  WorldObject::WorldObject(
      const std::shared_ptr<Model>& model,
      const glm::mat4& transform)
    : _model(model),
      _transform(transform)  {}
  
  WorldObject::WorldObject(const std::shared_ptr<Model>& model)
                          : WorldObject(model, glm::mat4()) { }

  void WorldObject::scaleUp() {
    glm::mat4 scaleUpMatrix;
    scaleUpMatrix = glm::scale(scaleUpMatrix, glm::vec3(1.1f, 1.1f, 1.1f));
    _transform = scaleUpMatrix * _transform;
  }

  void WorldObject::scaleDown() {
    glm::mat4 scaleDownMatrix;
    scaleDownMatrix = glm::scale(scaleDownMatrix, glm::vec3(0.9f, 0.9f, 0.9f));
    _transform = scaleDownMatrix * _transform;
  }
}
