#include "oglwindow.hpp"
#include "fpcamera.hpp"

namespace Core {
  FPCamera::FPCamera(const OglWindow& window) 
    : _window(window),
      speed(0.07f), 
      angular_speed(0.07f) { 
    initializeOpenGLFunctions();
    up.reset(new glm::vec3(0.0f, 1.0f, 0.0f)); 
    front.reset(new glm::vec3(0.0f, 0.0f, -1.0f)); 
    position.reset(new glm::vec3()); 
    projection.reset(
        new glm::mat4(
          glm::perspective(
            glm::radians(45.0f), 
            1.0f * _window.width() / _window.height(), 
            0.1f, 
            100.0f)));
  }

  glm::mat4 FPCamera::view() const {
    return glm::lookAt(*position, *position + *front, *up);
  }

  glm::mat4 FPCamera::vp_matrix() const {
    return *projection * view();
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

  void FPCamera::moveUp() {
    *position += speed * *up;
  }

  void FPCamera::moveDown() {
    *position -= speed * *up;
  }

  void FPCamera::lookLeft() {
    glm::mat4 rotation;
    rotation = glm::rotate(rotation, angular_speed, *up);
    *front = rotation * glm::vec4(*front, 1.0f);
  }

  void FPCamera::lookRight() {
    glm::mat4 rotation;
    rotation = glm::rotate(rotation, -angular_speed, *up);
    *front = rotation * glm::vec4(*front, 1.0f);
  }

  void FPCamera::lookUp() {
    glm::mat4 rotation;
    glm::vec3 axis = glm::cross(*up, *front);
    rotation = glm::rotate(rotation, -angular_speed, axis);
    *front = rotation * glm::vec4(*front, 1.0f);
    *up = rotation * glm::vec4(*up, 1.0f);
  }

  void FPCamera::lookDown() {
    glm::mat4 rotation;
    glm::vec3 axis = glm::cross(*up, *front);
    rotation = glm::rotate(rotation, angular_speed, axis);
    *front = rotation * glm::vec4(*front, 1.0f);
    *up = rotation * glm::vec4(*up, 1.0f);
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

