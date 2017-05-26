#include "fpcamera.hpp"

namespace Core {
  FPCamera::FPCamera() : speed(0.1f) { 
    initializeOpenGLFunctions();
    up.reset(new glm::vec3(0.0f, 1.0f, 0.0f)); 
    front.reset(new glm::vec3(0.0f, 0.0f, -1.0f)); 
    position.reset(new glm::vec3()); 
  }

  glm::mat4 FPCamera::view() const {
    return glm::lookAt(*position, *position + *front, *up);
  }

  void FPCamera::move(GLfloat dx, GLfloat dy, GLfloat dz) {
    position->x += dx;
    position->y += dy;
    position->z += dz;
  }

  void FPCamera::move2d(GLfloat dx, GLfloat dz) {
    move(dx, 0, dz);
  }

  void FPCamera::setPosition(GLfloat x, GLfloat y, GLfloat z) {
    position->x = x;
    position->y = y;
    position->z = z;
  }

  void FPCamera::moveForward() {
    *position += speed * *front;
  }

  void FPCamera::moveRight() {
    glm::vec3 rightDirection = glm::normalize(glm::cross(*front, *up));
    *position += speed * rightDirection;
  }

  void FPCamera::moveLeft() {
    glm::vec3 leftDirection = glm::normalize(glm::cross(*up, *front));
    *position += speed * leftDirection;
  }

  void FPCamera::moveBackward() {
    *position -= speed * *front;
  }

  std::ostream& operator<<(std::ostream& out, const Core::FPCamera& cam) {
    return out << "Position = (" << cam.position->x << ", "
                                 << cam.position->y << ", "
                                 << cam.position->z << ", "
                                 << ")" << std::endl
               << "Front = (" << cam.front->x << ", "
                              << cam.front->y << ", "
                              << cam.front->z << ", "
                              << ")" << std::endl
               << "Up = (" << cam.up->x << ", "
                           << cam.up->y << ", "
                           << cam.up->z << ", "
                           << ")" << std::endl;
  }
}

