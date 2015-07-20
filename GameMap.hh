#ifndef     GAMEMAP_HH_
#define     GAMEMAP_HH_

// mathematic include
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// gdl include
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
#include "Character.hpp"
#include "Bomb.hpp"

class Character;

class GameMap
{
    //Ctor && Dtor
public:
  GameMap(const int &, const int &, std::deque<Bomb *> &objects);
  ~GameMap();

  // Method
public:
  bool movePlayer(gdl::Clock const& clock, gdl::Input& input, Character &);
  void createCustomMap();
  void createMap(int);
  void createMap2();
  void createMap3();
  void createMap4();
  void createMap5();
  std::vector<AObject*> getWalls() const;
  std::vector<AObject*> getPlayers() const;
  int getCoordType(int, int) const;
  void showMap();
  void setTypeAtPos(int x, int z, int type);
  void putWall();
  void setRandomBonusAtPos(int x, int z);
  int **getMap() const;
  int getHeight() const;
  int getSpawnX(int) const;
  int getSpawnZ(int) const;

  // Attribut
private:
  typedef void (GameMap::*callMap)();
  int	_width;
  int	_height;
  int	**_map;
  callMap tab[4];
  int spawPoint[8][2];

  std::deque<Bomb *> &_objects;
  std::vector<AObject*> _players;
};

#endif
