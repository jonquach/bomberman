#ifndef     PLAYER_HPP_
#define     PLAYER_HPP_

// mathematic include
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// gdl include
#include <SdlContext.hh>
#include <Game.hh>
#include <Clock.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <Input.hh>
#include <AShader.hh>

// stl
#include <vector>
#include <iostream>

#include "Cube.hpp"
#include "GameMap.hh"
#include "Bomb.hpp"
#include "Character.hpp"
#include "Camera.hpp"

class Player
{
  // Attributs
private:
  Character *_character;
  GameMap &_map;
  Camera *_cam;
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  bool _dead;

  // Ctor && Dtor
public:
  Player(GameMap &);
  ~Player();

  // Methods
public:
  Character *getCharacter() const;
  bool initCharacter(std::deque<Bomb *> &objects, int);
  bool movePlayer(gdl::Clock const& clock, gdl::Input& input);
  void draw(gdl::AShader &shader, gdl::Clock const &clock);
  float getPosX();
  float getPosY();
  float getPosZ();
  bool getDead() const;
  Camera *getCamera();
};

#endif
