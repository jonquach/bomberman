#ifndef		CHARACTER_HPP_
# define        CHARACTER_HPP_

// GDL
#include <SDL_keycode.h>

// Other
#include "AObject.hpp"
#include "Exception.hpp"
#include "GameMap.hh"
#include "Bomb.hpp"

class GameMap;
class Bomb;

class Character : public AObject
{
public:
  enum eDirection
    {
      UP = 0,
      LEFT,
      DOWN,
      RIGHT,
      NONE
    };

  // Attributs
private:
  gdl::Texture		_texture;
  float			_speed;
  gdl::Model		_obj;
  int			_nbLife;
  eDirection		_dir;
  int			_id;
  int			_nbBomb;
  int			_nbBombMax;
  GameMap		&_map;
  std::deque<Bomb *>	&_objects;
  bool			&_dead;
  int			_powerBomb;
  double		_time;

public:
  // Ctor & Dtor
  // Character();
  Character(int, int, int, int, int, int, std::deque<Bomb *> &, GameMap &,
	    bool &);
  virtual ~Character();
  virtual bool initialize(int);
  void putBomb(gdl::Clock const &, gdl::Input &);
  virtual void update(gdl::Clock const &, gdl::Input &);
  virtual void updateP2(gdl::Clock const &, gdl::Input &);
  virtual void draw(gdl::AShader &, gdl::Clock const &);
  virtual char getLetter() const;
  void		die();

  // Getters
  gdl::Texture getTexture() const;
  float getSpeed() const;
  int getNbLife() const;
  int getNbBomb() const;
  int getId() const;

  // Setters
  void			setSpeed(float const);
  void			setNbLife(int const);
  void			setNbBomb(int);
  void			speedUp();
  void		        bombUp();
  void			powerUp();
};

#endif
