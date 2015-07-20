#include "Camera.hpp"

Camera::Camera(const glm::vec3 &position, const glm::vec3 &center) :
  _position(position), _center(center)
{
  // The transformation of the camera corresponds to its orientation
  // and its position : here, the camera is at position (0, 10, 10)
  // and it will be oriented towards the position (0, 0, 0)
  _up = glm::vec3(0, 1, 0);
}

Camera::~Camera()
{

}

const glm::mat4 &Camera::setPerspective(int _winX, int _winY)
{
  // glm::perspective(FOV, windowX / windowY, min plan, far plan)
  _transformation = glm::perspective(60.0f, static_cast<float>(_winX) /
				     static_cast<float>(_winY), 0.1f, 100.0f);
  return _transformation;
}

const glm::mat4 &Camera::setLookAt()
{
  // The projection of the camera corresponds to the way
  // the objects will be drawn on screen
  _projection = glm::lookAt(_position, _center, _up);
  return _projection;
}

void Camera::setPosition(const glm::vec3 &position)
{
  _position = position;
}

void Camera::setCenter(const glm::vec3 &center)
{
  _center = center;
}

void Camera::setUp(const glm::vec3 &up)
{
  _up = up;
}

const glm::vec3 &Camera::getPosition() const
{
  return _position;
}

const glm::vec3 &Camera::getCenter() const
{
  return _center;
}

const glm::vec3 &Camera::getUp() const
{
  return _up;
}
