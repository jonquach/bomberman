#ifndef	        EXPLOSION_HPP_
# define	EXPLOSION_HPP_

#include <iostream>
#include <list>
#include "Texture.hh"
#include "Geometry.hh"
#include "AObject.hpp"
#include "Bomb.hpp"
#include "GameMap.hh"

class GameMap;
class Bomb;

class Explosion : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float		_speed;
  std::string	_path;
  int		_delay;

  AObject	*_explosion;
  std::list<AObject*> _objects;

public:

  Explosion();
  Explosion(int Px, int Py, int Pz, int Rx, int Ry, int Rz);

  virtual ~Explosion() { }
  virtual bool initialize();

  void	impact(GameMap &, int pow);
  void	clearExplosion(GameMap &, int pow);
  void  toRenew(GameMap &, int pow);

  virtual void update(gdl::Clock const &clock, gdl::Input &input, std::deque<Bomb *> & objects);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual char getLetter() const;
};

#endif
