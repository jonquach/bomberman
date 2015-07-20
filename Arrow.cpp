#include "Arrow.hpp"

Arrow::Arrow(int Px, int Py, int Pz, int Rx, int Ry, int Rz,
	     std::string const &path) : AObject(Px, Py, Pz, Rx, Ry, Rz)
{
  _path = path;
}

bool Arrow::initialize()
{
  _speed = 10.0f;
  pos = 0;

  if (_texture.load(_path) == false)
    return (false);

  // back side
  _geometry.pushVertex(glm::vec3(3, -3, 3));
  _geometry.pushVertex(glm::vec3(3, 3, 3));
  _geometry.pushVertex(glm::vec3(-3, 3, 3));
  _geometry.pushVertex(glm::vec3(-3, -3, 3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.build();
  return (true);
}

void Arrow::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  static_cast<void>(clock);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void Arrow::update(gdl::Clock const &clock, gdl::Input &input)
{
  static_cast<void>(clock);

  // left
  if (input.getKey(SDLK_LEFT, true))
    {
      if (pos > 0)
	{
	  --pos;
	  translate(glm::vec3(-6, 0, 0));
	}
    }

  // right
  if (input.getKey(SDLK_RIGHT, true))
    {
      if (pos < 3)
	{
	  ++pos;
	  translate(glm::vec3(6, 0, 0));
	}
    }
}

char    Arrow::getLetter() const
{
  return _letter;
}
