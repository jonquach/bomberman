#include "Button.hpp"

Button::Button(int Px, int Py, int Pz, int Rx,
	       int Ry, int Rz, std::string const &path)
  : AObject(Px, Py, Pz, Rx, Ry ,Rz)
{
  _path = path;
}

bool Button::initialize()
{
  _speed = 10.0f;
  _pos = 0;
  if (_texture.load(_path) == false)
    return (false);

  // back side
  _geometry.pushVertex(glm::vec3(1, -2, -2));
  _geometry.pushVertex(glm::vec3(1, 2, -2));
  _geometry.pushVertex(glm::vec3(-1, 2, -2));
  _geometry.pushVertex(glm::vec3(-1, -2, -2));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.build();
  return (true);
}

void Button::update(gdl::Clock const &clock, gdl::Input &input)
{
  static_cast<void>(clock);
  static_cast<void>(input);
  /*    if (input.getKey(SDLK_UP))
	{
	if (_pos == 0)
	_pos = 3;
	else
	_pos -= 1;
	translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
	}
	if (input.getKey(SDLK_DOWN))
	{
	if (_pos == 3)
	_pos = 0;
	else
	_pos += 1;
	translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
	}*/
}

void Button::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  static_cast<void>(clock);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

char    Button::getLetter() const
{
  return _letter;
}
