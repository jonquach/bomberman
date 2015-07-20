#ifndef		BOMB_HPP_
# define	BOMB_HPP_

#include <iostream>

#include "Texture.hh"
#include "Geometry.hh"
#include "AObject.hpp"
#include "GameMap.hh"
#include "Explosion.hpp"

class Player;
class GameMap;
class Explosion;

class Bomb : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float		_speed;
  std::string	_path;
  int		_exploded;
  double	_time;
  Player	*_p;
  Explosion	*_xplosion;
  int		&_nbBomb;
  Bomb		*_bomb;
  GameMap	&_map;
  int		_power;

public:
  Bomb(GameMap &, int&);
  Bomb(float Px, float Py, float Pz, float Rx, float Ry, float Rz,
       int &nbBomb, GameMap &gm);

  virtual ~Bomb();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input,
		      std::deque<Bomb *> & objects);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual char getLetter() const;

  bool  isBomb() const;
  void	setPower(int power);
  void  putBomb(std::deque<Bomb *> & objects, int powerBomb);

};

#endif
