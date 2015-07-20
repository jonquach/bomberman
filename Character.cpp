#include "Bomb.hpp"
#include "Character.hpp"

Character::Character(int Px, int Py, int Pz, int Rx, int Ry, int Rz,
		     std::deque<Bomb *> &objects, GameMap &gm,
		     bool & dead) :
  AObject(Px, Py, Pz, Rx, Ry, Rz), _map(gm), _objects(objects), _dead(dead)
{
  _dir = DOWN;
  _nbBomb = 0;
  _nbBombMax = 1;
  _powerBomb = 3;
  _time = 0;
}

Character::~Character()
{}

// Methods
bool Character::initialize(int id)
{
 	this->_id = id;
 	_speed = 5.0f;

 // Texture loading
  if (_texture.load("./LibBomberman_linux_x64/assets/marvin.fbm/Main_texture_diffuse2.tga")
      == false)
    return (false);

  // 3D Character loading
  if (_obj.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    throw ErrorException("Error : object load failed in Character.cpp");

  // Player position
  translate(glm::vec3(1, -0.5, 1));

  // Zoom
  scale(glm::vec3(0.0025, 0.0025, 0.0025));

  _obj.createSubAnim(0, "stop", 0, 0);
  _obj.createSubAnim(0, "start walking", 0, 30);
  _obj.createSubAnim(0, "running", 30, 60);

  _obj.setCurrentSubAnim("running");

  _obj.setCurrentAnim(59, true);

  return true;
}

// Param : Clock, Input
// Description :
// Character will move with the inputs
// Movement depends on the clock and speed which are set in the ctor
void		Character::putBomb(gdl::Clock const &clock, gdl::Input &input)
{
  static_cast<void>(clock);
  if ((input.getKey(SDLK_KP_0) && _id == 1) || (input.getKey(SDLK_SPACE) && _id == 2))
    {
      if (_nbBomb < _nbBombMax)
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

	  if (_map.getCoordType(z, x) != 5 && _map.getCoordType(z, x) != 6)
	    {
	      Bomb *_bomb = new Bomb(x, getPosY(), z, 0, 0, 0, _nbBomb, _map);
	      if (_bomb->initialize() == false)
		throw ErrorException("Error : bomb initialize failed in bomb.cpp");
	      ++_nbBomb;
	      _bomb->setPower(_powerBomb);
	      _objects.push_back(_bomb);
	      _map.setTypeAtPos(x, z, 6);
	    }
      	}
    }
}

void		Character::update(gdl::Clock const &clock, gdl::Input &input)
{
  // down
  if (input.getKey(SDLK_DOWN))
    {
      switch (_dir)
	{
	case RIGHT:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	case DOWN:
	  rotate(glm::vec3(0.0f, -180.0f, 0.0f), 1);
	  break;
	case LEFT:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = UP;
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    }

  // up
  if (input.getKey(SDLK_UP))
    {
      switch (_dir)
	{
	case RIGHT:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	case UP:
	  rotate(glm::vec3(0.0f, -180.0f, 0.0f), 1);
	  break;
	case LEFT:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = DOWN;
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    }

  // right
  if (input.getKey(SDLK_RIGHT))
    {
      switch (_dir)
	{
	case RIGHT:
	  rotate(glm::vec3(0.0f, -180.0f, 0.0f), 1);
	  break;
	case UP:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	case DOWN:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = LEFT;
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }

  // left
  if (input.getKey(SDLK_LEFT))
    {
      switch (_dir)
	{
	case DOWN:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	case UP:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	case LEFT:
	  rotate(glm::vec3(0.0f, 180.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = RIGHT;
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  else
    _obj.setCurrentAnim("stop", true);
}

void		Character::updateP2(gdl::Clock const &clock, gdl::Input &input)
{
  // SPACE
  if (input.getKey(SDLK_SPACE) && _id == 2)
    {
      if (_nbBomb < _nbBombMax && _time <= 0)
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
	  Bomb	*_bomb = new Bomb(x, getPosY(), z, 0, 0, 0, _nbBomb, _map);
	  if (_bomb->initialize() == false)
	    throw ErrorException("Error : bomb initialize failed in Character.cpp");
	  _bomb->putBomb(_objects, _powerBomb); // Player's position
	  _time = 0.2;
	}
    }

  // S
  if (input.getKey(SDLK_s))
    {
      switch (_dir)
	{
	case RIGHT:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	case DOWN:
	  rotate(glm::vec3(0.0f, -180.0f, 0.0f), 1);
	  break;
	case LEFT:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = UP;
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    }

  // Z
  if (input.getKey(SDLK_z))
    {
      switch (_dir)
	{
	case RIGHT:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	case UP:
	  rotate(glm::vec3(0.0f, -180.0f, 0.0f), 1);
	  break;
	case LEFT:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = DOWN;
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    }

  // D
  if (input.getKey(SDLK_d))
    {
      switch (_dir)
	{
	case RIGHT:
	  rotate(glm::vec3(0.0f, -180.0f, 0.0f), 1);
	  break;
	case UP:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	case DOWN:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = LEFT;
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }

  // Q
  if (input.getKey(SDLK_q))
    {
      switch (_dir)
	{
	case DOWN:
	  rotate(glm::vec3(0.0f, 90.0f, 0.0f), 1);
	  break;
	case UP:
	  rotate(glm::vec3(0.0f, -90.0f, 0.0f), 1);
	  break;
	case LEFT:
	  rotate(glm::vec3(0.0f, 180.0f, 0.0f), 1);
	  break;
	default:
	  break;
	};
      _dir = RIGHT;
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  else
    _obj.setCurrentAnim("stop", true);
}

void Character::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  static_cast<void>(clock);
  _texture.bind();
  _obj.draw(shader, getTransformation(), clock.getElapsed());
}

char    Character::getLetter() const
{
  return _letter;
}

// Getters
gdl::Texture	Character::getTexture() const
{
  return _texture;
}

float		Character::getSpeed() const
{
  return _speed;
}

int		Character::getNbLife() const
{
  return _nbLife;
}

int		Character::getNbBomb() const
{
  return _nbBomb;
}

int		Character::getId() const
{
  return _id;
}

// Setters
void		Character::setSpeed(float const other)
{
  this->_speed = other;
}

void		Character::die()
{
  _dead = true;
}

void		Character::setNbLife(int const other)
{
  this->_nbLife = other;
}

void		Character::speedUp()
{
  ++this->_speed;
}

void		Character::bombUp()
{
  ++this->_nbBombMax;
}

void		Character::powerUp()
{
  ++this->_powerBomb;
}
