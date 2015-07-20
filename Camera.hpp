#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
  glm::mat4 _projection;
  glm::mat4 _transformation;
  glm::vec3 _position;
  glm::vec3 _center;
  glm::vec3 _up;

public:
  Camera(const glm::vec3 &, const glm::vec3 &);
  ~Camera();
  const glm::mat4 &setPerspective(int, int);
  const glm::mat4 &setLookAt();
  void setPosition(const glm::vec3 &);
  void setCenter(const glm::vec3 &);
  void setUp(const glm::vec3 &);
  const glm::vec3 &getPosition() const;
  const glm::vec3 &getCenter() const;
  const glm::vec3 &getUp() const;
};

#endif
