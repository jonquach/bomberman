#include "Explosion.hpp"

Explosion::Explosion()
  : AObject(0, 0, 0, 0, 0, 0)
{
  _delay = 5;
  _path = "./img/explosion.tga";
  setState(AObject::UNDEFINED);
}

Explosion::Explosion(int Px, int Py, int Pz, int Rx, int Ry, int Rz)
  : AObject(Px, Py, Pz, Rx, Ry ,Rz)
{
  _delay = 5;
  _path = "./img/explosion.tga";
  setState(AObject::UNDEFINED);
}

bool    Explosion::initialize()
{
  _speed = 10.0f;
  if (_texture.load(_path) == false)
    return (false);

  // back side
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // front side
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // left side
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // right side
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // up side
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // down side
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.build();
  return (true);
}

void	Explosion::impact(GameMap &map, int pow)
{
  int	xpos = getPosX();
  int	zpos = getPosZ();
  int	i;

  // right
  map.setTypeAtPos(xpos, zpos, 7);
  for (i = 1; i < pow; ++i)
    {
      if (map.getCoordType(zpos, xpos + i) == 1)
	break;
      else if (map.getCoordType(zpos, xpos + i) == 4)
	{
	  map.setRandomBonusAtPos(xpos + i, zpos);
	  break;
	}
      map.setTypeAtPos(xpos +i, zpos, 7);
    }

  // up
  for (i = -1; i > -pow; --i)
    {
      if (map.getCoordType(zpos, xpos + i) == 1)
	break;
      else if (map.getCoordType(zpos, xpos + i) == 4)
	{
	  map.setRandomBonusAtPos(xpos + i, zpos);
	  break;
	}
      map.setTypeAtPos(xpos + i, zpos, 7);
    }

  // up
  for (i = 1; i < pow; ++i)
    {
      if (map.getCoordType(zpos + i, xpos) == 1)
	break;
      else if (map.getCoordType(zpos + i, xpos) == 4)
      	{
      	  map.setRandomBonusAtPos(xpos, zpos + i);
      	  break;
      	}
      map.setTypeAtPos(xpos, zpos + i, 7);
    }

  // down
  for (i = -1; i > -pow; --i)
    {
      if (map.getCoordType(zpos + i, xpos) == 1)
	break;
      else if (map.getCoordType(zpos + i, xpos) == 4)
      	{
      	  map.setRandomBonusAtPos(xpos, zpos + i);
      	  break;
      	}
      map.setTypeAtPos(xpos, zpos + i, 7);
    }
}

void	Explosion::toRenew(GameMap &map, int pow)
{
  int	xpos = getPosX();
  int	zpos = getPosZ();
  int	i;

  // right
  if (map.getCoordType(zpos, xpos) == 7 || map.getCoordType(zpos, xpos) == 0)
    map.setTypeAtPos(xpos, zpos, 7);

  for (i = 1; i < pow; ++i)
    if (map.getCoordType(zpos, xpos + i) == 7 ||
	map.getCoordType(zpos, xpos + i) == 0)
      map.setTypeAtPos(xpos + i, zpos, 7);
    else
      break;

  //left
  for (i = -1; i > -pow; --i)
    {
      if (map.getCoordType(zpos, xpos + i) == 7 ||
	  map.getCoordType(zpos, xpos + i) == 0)
	map.setTypeAtPos(xpos + i, zpos, 7);
      else
	break;
    }

  // up
  for (i = 1; i < pow; ++i)
    {
      if (map.getCoordType(zpos + i, xpos) == 7 ||
	  map.getCoordType(zpos + i, xpos) == 0)
	map.setTypeAtPos(xpos, zpos + i, 7);
      else
	break;
    }

  // down
  for (i = -1; i > -pow; --i)
    {
      if (map.getCoordType(zpos + i, xpos) == 7 ||
	  map.getCoordType(zpos + i, xpos) == 0)
	map.setTypeAtPos(xpos, zpos + i, 7);
      else
	break;
    }
}

char    Explosion::getLetter() const
{
  return _letter;
}

void	Explosion::clearExplosion(GameMap &map, int pow)
{
  int	xpos = getPosX();
  int	zpos = getPosZ();
  int	i;

  // right
  if (map.getCoordType(zpos, xpos) == 7)
    map.setTypeAtPos(xpos, zpos, 0);

  for (i = 1; i < pow; ++i)
    if (map.getCoordType(zpos, xpos + i) == 7)
      map.setTypeAtPos(xpos + i, zpos, 0);

  // left
  for (i = -1; i > -pow; --i)
    {
      if (map.getCoordType(zpos, xpos + i) == 7)
	map.setTypeAtPos(xpos + i, zpos, 0);
    }

  // up
  for (i = 1; i < pow; ++i)
    {
      if (map.getCoordType(zpos + i, xpos) == 7)
	map.setTypeAtPos(xpos, zpos + i, 0);
    }

  // down
  for (i = -1; i > -pow; --i)
    {
      if (map.getCoordType(zpos + i, xpos) == 7)
	map.setTypeAtPos(xpos, zpos + i, 0);
    }
}

void	Explosion::update(gdl::Clock const &clock, gdl::Input &input,
			  std::deque<Bomb *> & objects)
{
  static_cast<void>(clock);
  static_cast<void>(input);
  static_cast<void>(objects);
}

void	Explosion::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  static_cast<void>(clock);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
