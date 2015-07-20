#include "AObject.hpp"

AObject::AObject() :
  _position(0, 0, 0),
  _rotation(0, 0, 0),
  _scale(1, 1, 1),
  _state(UNDEFINED),
  _letter('a')
{}

AObject::AObject(int Px, int Py, int Pz, int Rx, int Ry, int Rz) :
  _position(Px, Py, Pz),
  _rotation(Rx, Ry, Rz),
  _scale(1, 1, 1),
  _state(UNDEFINED),
  _letter('a')
{}

bool    AObject::initialize()
{
  return true;
}

void    AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  static_cast<void>(clock);
  static_cast<void>(input);
}

void    AObject::update(gdl::Clock const &clock, gdl::Input &input,
			std::string mode)
{
  static_cast<void>(clock);
  static_cast<void>(input);
  static_cast<void>(mode);
}

void    AObject::update(gdl::Clock const &clock, gdl::Input &input,
			std::deque<AObject *> & dynamicObjects)
{
  static_cast<void>(clock);
  static_cast<void>(input);
  static_cast<void>(dynamicObjects);
}

void	AObject::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  static_cast<void>(shader);
  static_cast<void>(clock);
}

char	AObject::getLetter() const
{
  return _letter;
}

void			AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void			AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void			AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4		AObject::getTransformation()
{
  glm::mat4 transform(1);

  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, _scale);
  return transform;
}

float	AObject::getPosX() const
{
  return (_position.x);
}

float	AObject::getPosY() const
{
  return (_position.y);
}

float	AObject::getPosZ() const
{
  return (_position.z);
}

int AObject::getNbValue() const
{
  return -1;
}

void	AObject::setPosX(float x)
{
  _position.x = x;
}

void	AObject::setPosY(float y)
{
  _position.y = y;
}

void	AObject::setPosZ(float z)
{
  _position.z = z;
}

void	AObject::setState(eState other)
{
  _state = other;
}

AObject::eState AObject::getState() const
{
  return _state;
}

void  AObject::setSetting(bool setting)
{
  _setting = setting;
}
