#ifndef FPCAMERA_HPP
#define FPCAMERA_HPP

#include <QOpenGLExtraFunctions>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <ostream>

class OglWidget;

namespace Core {
class FPCamera : QOpenGLExtraFunctions {
public:
  FPCamera(int viewWidth, int viewHeight);

  glm::mat4 view() const;
  glm::mat4 vp_matrix() const;

  void move(GLfloat dx, GLfloat dy, GLfloat dz);
  void move2d(GLfloat dx, GLfloat dz);
  void setPosition(GLfloat x, GLfloat y, GLfloat z);

  void moveRight();
  void moveLeft();
  void moveForward();
  void moveBackward();
  void moveUp();
  void moveDown();
  void lookLeft();
  void lookRight();
  void lookUp();
  void lookDown();

  GLfloat speed;
  GLfloat angular_speed;
  std::unique_ptr<glm::vec3> up;
  std::unique_ptr<glm::vec3> front;
  std::unique_ptr<glm::vec3> position;
  std::unique_ptr<glm::mat4> projection;

  friend std::ostream& operator<<(std::ostream& out, const FPCamera& cam);
};

}

#endif
