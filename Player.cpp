#include "Player.hpp"

Player::Player(GameMap &gm) :
  _map(gm)
{
  _cam = new Camera(glm::vec3(0, 10, 10), glm::vec3(0, 0, 0));
}

Player::~Player() {}

bool Player::initCharacter(std::deque<Bomb *> &objects, int id)
{
  static int spawn = 0;
  _character = new Character(0, 0, 0, 0, 0, 0, objects, _map, _dead);
  if (_character->initialize(id) == false)
    throw ErrorException("Error : texture load failed in Character.cpp");

  if (id == 1)
    spawn = 0;

  _character->setPosX(_map.getSpawnX(spawn));
  _character->setPosZ(_map.getSpawnZ(spawn));
  if (spawn < 7)
    ++spawn;
  return true;
}

Character *Player::getCharacter() const
{
  return (_character);
}

bool	Player::movePlayer(gdl::Clock const &clock, gdl::Input &input)
{
  return (_map.movePlayer(clock, input, *_character));
}

void Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _character->draw(shader, clock);
}

float Player::getPosX()
{
  return (_character->getPosX());
}

float Player::getPosZ()
{
  return (_character->getPosZ());
}

float Player::getPosY()
{
  return (_character->getPosY());
}

bool Player::getDead() const
{
  return _dead;
}

Camera *Player::getCamera()
{
  return _cam;
}
