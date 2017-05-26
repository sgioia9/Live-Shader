#ifndef FPCAMERA_HPP
#define FPCAMERA_HPP

#include <QOpenGLExtraFunctions>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <ostream>

namespace Core {
class FPCamera : QOpenGLExtraFunctions {
public:
  FPCamera();

  glm::mat4 view() const;

  void move(GLfloat dx, GLfloat dy, GLfloat dz);
  void move2d(GLfloat dx, GLfloat dz);
  void setPosition(GLfloat x, GLfloat y, GLfloat z);

  void moveRight();
  void moveLeft();
  void moveForward();
  void moveBackward();

  GLfloat speed;
  std::unique_ptr<glm::vec3> up;
  std::unique_ptr<glm::vec3> front;
  std::unique_ptr<glm::vec3> position;

  friend std::ostream& operator<<(std::ostream& out, const FPCamera& cam);
};

}

#endif
