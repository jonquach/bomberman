#include <SdlContext.hh>

#include "Player.hpp"
#include "Bomb.hpp"

Bomb::Bomb(GameMap& map, int &nbBomb) :
  AObject(0, 0, 0, 0, 0, 0),
  _nbBomb(nbBomb),
  _map(map)
{
  _path = "./img/tnt.tga";
  _time = 4;
  _exploded = 0;
  _power = 3;
  setState(AObject::BOMB);
}

Bomb::Bomb(float Px, float Py, float Pz, float Rx, float Ry, float Rz,
	   int &nbBomb, GameMap& map) :
  AObject(Px, Py, Pz, Rx, Ry ,Rz),
  _nbBomb(nbBomb),
  _map(map)
{
  _path = "./img/tnt.tga";
  _time = 4;
  _exploded = 0;
  _power = 3;
  setState(AObject::BOMB);
}

Bomb::~Bomb()
{
}

bool Bomb::initialize()
{
  _speed = 10.0f;
  if (_texture.load(_path) == false)
    return (false);

  // back side
  _geometry.setColor(glm::vec4(1, 0, 0, 1));
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

void Bomb::update(gdl::Clock const &clock, gdl::Input &input,
		  std::deque<Bomb *> & objects)
{
  static_cast<void>(input);
  static_cast<void>(objects);
  if (_time > 0)
    _time -= clock.getElapsed();
  if (_time < 3.0 && _time > 1.5)
    _map.setTypeAtPos(getPosX(), getPosZ(), 5);

  if (_time > 1.0 && _time < 1.5 && getState() != AObject::EXPLODED)
    {
      _xplosion = new Explosion(getPosX(), getPosY(), getPosZ(), 0, 0, 0);
      if (_xplosion->initialize() == false)
        throw ErrorException("Error : Explosion initialize failed in bomb.cpp");
      _xplosion->impact(_map, _power);
      setState(AObject::EXPLODED);
    }
  if (getState() == AObject::EXPLODED)
    _xplosion->toRenew(_map, _power);
  if (_time < 0.7 && getState() != AObject::TODESTROY)
    {
      if (_nbBomb > 0)
  	--_nbBomb;
      _xplosion->clearExplosion(_map, _power);
      _map.setTypeAtPos(getPosX(), getPosZ(), 0);
      setState(AObject::TODESTROY);
    }
}

void Bomb::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  static_cast<void>(clock);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

char    Bomb::getLetter() const
{
  return _letter;
}

bool Bomb::isBomb() const
{
  return (false);
}

void Bomb::setPower(int power)
{
  this->_power = power;
}

void Bomb::putBomb(std::deque<Bomb *> & objects, int powerBomb)
{
  int x = 0;
  int z = 0;

  if (x < -0.5f)
    x = getPosX() - 0.5f;
  else
    x = getPosX() + 0.5f;
  if (z < -0.5f)
    z = getPosZ() - 0.5f;
  else
    z = getPosZ() + 0.5f;
  _bomb = new Bomb(x, getPosY(), z, 0, 0, 0, _nbBomb, _map);
  if (_bomb->initialize() == false)
    throw ErrorException("Error : bomb initialize failed in bomb.cpp");
  ++_nbBomb;
  _bomb->setPower(powerBomb);
  objects.push_back(_bomb);
  _map.setTypeAtPos(getPosX(), getPosZ(), 6);
}
