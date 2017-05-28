#include "worldobject.hpp"

namespace Core {
  WorldObject::WorldObject(
      const std::shared_ptr<Model>& model,
      const glm::mat4& transform)
    : _model(model),
      _transform(transform)  {}
  
  WorldObject::WorldObject(const std::shared_ptr<Model>& model)
                          : WorldObject(model, glm::mat4()) { }
}
