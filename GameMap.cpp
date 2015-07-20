#include "GameMap.hh"

GameMap::GameMap(int const & width, int const & height, std::deque<Bomb *> &objects): _objects(objects)
{
  if (width >= 10)
    _width = width;
  else
    _width = 10;
  if (height >= 10)
    _height = height;
  else
    _height = 10;
  _map = new int*[_height];
}

GameMap::~GameMap() {}

void GameMap::createMap3()
{
  _height = 23;
  _width = 23;
  int	mid_h = _height / 2;
  int	mid_w = _width / 2;
  for (int z = 0; z < _height; ++z)
    {
      _map[z] = new int[_width];
      for (int x = 0; x < _width; ++x)
        {
	  if (z == 0 || x == 0 || z == _height - 1 || x == _width - 1)
	    _map[z][x] = 1;
	  else if ((z - mid_h <= 2 && z - mid_h >= -2) && (x - mid_w <= 2 && x - mid_w >= -2))
	    _map[z][x] = 1;
	  else if ((z == _height - 2 && x == 3) || (z == 3 && x == _width - 2) || (z == 1 && x == _width - 4) || (z == _height - 4 && x == 1))
	    _map[z][x] = 4;
	  else if ((z == 3 && x == 1) || (z == 1 && x == 3) || (z == _height - 2 && x == _width - 4) || (z == _height - 4 && x == _width - 2))
	    _map[z][x] = 4;
	  else if ((z == x || z + x == _height - 1) && z != 1 && z != _height - 2)
	    _map[z][x] = 4;
	  else
	    _map[z][x] = 0;
        }
    }
}

void GameMap::createMap2()
{
  _height = 23;
  _width = 23;
  int	mid_h = _height / 2;
  int	mid_w = _width / 2;
  for (int z = 0; z < _height; ++z)
    {
      _map[z] = new int[_width];
      for (int x = 0; x < _width; ++x)
        {
	  if (z == 0 || x == 0 || z == _height - 1 || x == _width - 1)
	    _map[z][x] = 1;
	  else if ((z - mid_h <= 2 && z - mid_h >= -2) || (x - mid_w <= 2 && x - mid_w >= -2))
	    _map[z][x] = 4;
	  else
	    _map[z][x] = 0;
        }
    }
}

void GameMap::createMap4()
{
  _height = 23;
  _width = 23;
  for (int z = 0; z < _height; ++z)
    {
      _map[z] = new int[_width];
      for (int x = 0; x < _width; ++x)
        {
	  if (z == 0 || x == 0 || z == _height - 1 || x == _width - 1)
	    _map[z][x] = 1;
	  else if (z % 2 == 0 && x % 2 == 0)
	    _map[z][x] = 4;
	  else if ((_map[z][x] == 0) && (x % 2 == 0) && (x - 1 != _width) && (x + 1 != _width) && (z - 1 != _height) && (z + 1 != _height) )
	    _map[z][x] = 4;
	  else
	    _map[z][x] = 0;
        }
    }
}

void GameMap::createMap5()
{
  _height = 23;
  _width = 23;
  for (int z = 0; z < _height; ++z)
    {
      _map[z] = new int[_width];
      for (int x = 0; x < _width; ++x)
        {
	  if (z == 0 || x == 0 || z == _height - 1 || x == _width - 1)
	    _map[z][x] = 1;
	  else if (z % 2 == 0 && x % 2 == 0)
	    _map[z][x] = 4;
	  else
	    _map[z][x] = 0;
        }
    }
}

void	GameMap::createMap(int map)
{
  tab[0] = &GameMap::createMap2;
  tab[1] = &GameMap::createMap3;
  tab[2] = &GameMap::createMap4;
  tab[3] = &GameMap::createMap5;

  (this->*tab[map])();

  spawPoint[0][0] = 1;
  spawPoint[0][1] = 1;
  spawPoint[1][0] = _height - 2;
  spawPoint[1][1] = _width - 2;
  spawPoint[2][0] = _height - 2 ;
  spawPoint[2][1] = 1;
  spawPoint[3][0] = 1;
  spawPoint[3][1] = _width - 2;
  spawPoint[4][0] = 3;
  spawPoint[4][1] = _width - 4;
  spawPoint[5][0] = _width - 4;
  spawPoint[5][1] = 3;
  spawPoint[6][0] = 3;
  spawPoint[6][1] = 3;
  spawPoint[7][0] = _width - 4;
  spawPoint[7][1] = _width - 4;
}

void GameMap::createCustomMap()
{
  for (int z = 0; z < _height; ++z)
    {
      _map[z] = new int[_width];
      for (int x = 0; x < _width; ++x)
        {
	  if ((z == 1 && x == 1) || (z == 1 && x == _height - 2) ||
	      (z == _height - 2 && x == _width - 2) || (x == 1 && z == _width - 2))
	    _map[z][x] = 0;
	  else if (z == 0 || x == 0 || z == _height - 1 || x == _width - 1)
	    _map[z][x] = 1;
	  else if (z % 2 == 0 && x % 2 == 0)
	    _map[z][x] = 1;
	  else if (z % 2 == 1 && x % 2 == 1)
	    _map[z][x] = 4;
	  else
	    _map[z][x] = 0;
        }
    }
  spawPoint[0][0] = 1;
  spawPoint[0][1] = 1;
  spawPoint[1][0] = 1;
  spawPoint[1][1] = 1;
  spawPoint[2][0] = 1;
  spawPoint[2][1] = 1;
  spawPoint[3][0] = 1;
  spawPoint[3][1] = 1;
  spawPoint[4][0] = 1;
  spawPoint[4][1] = 1;
  spawPoint[5][0] = 1;
  spawPoint[5][1] = 1;
  spawPoint[6][0] = 1;
  spawPoint[6][1] = 1;
  spawPoint[7][0] = 1;
  spawPoint[7][1] = 1;
}

void	GameMap::putWall()
{
  for (int i = 0; i < _height; i++)
    {
      for (int j = 0; j < _width; j++)
  	{
  	  if ((_map[i][j] == 0) && (j % 2 == 0) && (j - 1 != _width) && (j + 1 != _width) && (i - 1 != _height) && (i + 1 != _height) )
  	    {
  	      _map[i][j] = 4;
  	    }
  	}
    }
}

bool GameMap::movePlayer(gdl::Clock const &clock, gdl::Input &input, Character &chara)
{
  float fold_x = chara.getPosX();
  float fold_z = chara.getPosZ();
  int old_x;
  int old_z;
  int old_x1;
  int old_z1;
  int x;
  int z;
  int x1;
  int z1;

  if ((input.getKey(SDLK_KP_0) && chara.getId() == 1) || (input.getKey(SDLK_SPACE) && chara.getId() == 2))
    {
      chara.putBomb(clock, input);
      return true;
    }
  if (chara.getPosX() < -0.5f)
    {
      old_x = chara.getPosX() - 0.4f;
      old_x1 = chara.getPosX() - 0.6f;
    }
  else
    {
      old_x = chara.getPosX() + 0.6f;
      old_x1 = chara.getPosX() + 0.4f;
    }
  if (chara.getPosZ() < -0.5f)
    {
      old_z = chara.getPosZ() - 0.4f;
      old_z1 = chara.getPosZ() - 0.6f;
    }
  else
    {
      old_z = chara.getPosZ() + 0.6f;
      old_z1 = chara.getPosZ() + 0.4f;
    }

  if (chara.getId() == 1)
    chara.update(clock, input);
  else if (chara.getId() == 2)
    chara.updateP2(clock, input);
  if (chara.getPosX() < -0.5f)
    {
      x = chara.getPosX() - 0.4f;
      x1 = chara.getPosX() - 0.6f;
    }
  else
    {
      x = chara.getPosX() + 0.6f;
      x1 = chara.getPosX() + 0.4f;
    }
  if (chara.getPosZ() < -0.5f)
    {
      z = chara.getPosZ() - 0.4f;
      z1 = chara.getPosZ() - 0.6f;
    }
  else
    {
      z = chara.getPosZ() + 0.6f;
      z1 = chara.getPosZ() + 0.4f;
    }

  if (x1 < _height && z1 < _width && x >= 0 && z >= 0)
    if (x < _height && z < _width && x1 >= 0 && z1 >= 0)
      {
  if (_map[old_z][old_x] == 7 && _map[old_z1][old_x1] == 7 && _map[old_z][old_x1] == 7 && _map[old_z1][old_x] == 7)
    {
      chara.die();
      return (true);
    }
  else if (_map[z][x] != 1 && _map[z1][x1] != 1 && _map[z][x1] != 1 && _map[z1][x] != 1
      && _map[z][x] != 4 && _map[z1][x1] != 4 && _map[z][x1] != 4 && _map[z1][x] != 4
      && _map[z][x] != 5 && _map[z1][x1] != 5 && _map[z][x1] != 5 && _map[z1][x] != 5)
    {
      if (_map[old_z][old_x] == 2 && _map[old_z1][old_x1] == 2 && _map[old_z][old_x1] == 2 && _map[old_z1][old_x] == 2)
        {
    _map[old_z][old_x] = 0;
    _map[old_z1][old_x1] = 0;
    _map[old_z1][old_x] = 0;
    _map[old_z][old_x1] = 0;
        }

      if (_map[z][x] == 0 && _map[z1][x1] == 0 && _map[z][x1] == 0 && _map[z1][x] == 0)
        {
    _map[z][x] = 2;
    _map[z1][x1] = 2;
    _map[z1][x] = 2;
    _map[z][x1] = 2;
        }

      if (_map[z][x] == 7 && _map[z1][x1] == 7 && _map[z][x1] == 7 && _map[z1][x] == 7)
        {
    chara.die();
    return (true);
        }

      if (_map[z][x] >= 9 && _map[z1][x1] >= 9 && _map[z][x1] >= 9 && _map[z1][x] >= 9)
        {
    if (_map[z][x] == AObject::POWERUP && _map[z1][x1] == AObject::POWERUP &&
        _map[z][x1] == AObject::POWERUP && _map[z1][x] == AObject::POWERUP)
      chara.powerUp();
    if (_map[z][x] == AObject::BOMBUP && _map[z1][x1] == AObject::BOMBUP &&
        _map[z][x1] == AObject::BOMBUP && _map[z1][x] == AObject::BOMBUP)
      chara.bombUp();
    if (_map[z][x] == AObject::SPEEDUP && _map[z1][x1] == AObject::SPEEDUP &&
        _map[z][x1] == AObject::SPEEDUP && _map[z1][x] == AObject::SPEEDUP)
      chara.speedUp();
    _map[z][x] = 2;
    _map[z1][x1] = 2;
    _map[z1][x] = 2;
    _map[z][x1] = 2;
        }
      return (true);
    }
      }

  chara.setPosX(fold_x);
  chara.setPosZ(fold_z);
  return (false);
}

void	GameMap::showMap()
{
  for (int z = 0; z < _width; ++z)
    {
      std::cout << z << "\t";
      for (int x = 0; x < _height; ++x)
	std::cout << _map[z][x];
      std::cout << std::endl;
    }
  std::cout << "\n\n\n------------------------------------\n\n\n" << std::endl;
}

std::vector<AObject*> GameMap::getPlayers() const
{
  return (_players);
}

int GameMap::getCoordType(int z, int x) const
{
  if (x < _height && z < _width && x >= 0 && z >= 0)
    {
      return (_map[z][x]);
    }
  return (0);
}

void GameMap::setTypeAtPos(int x, int z, int type)
{
  if (x < _height && z < _width && x >= 0 && z >= 0 && _map[z][x] != 1)
    {
      _map[z][x] = type;
    }
}

void GameMap::setRandomBonusAtPos(int x, int z)
{
  int ret = (rand() % 100) + 1;

  if (ret >= 1 && ret <= 60)
    _map[z][x] = 3;
  else if (ret > 60 && ret <= 80)
    _map[z][x] = AObject::BOMBUP;
  else if (ret > 80 && ret <= 85)
    _map[z][x] = AObject::SPEEDUP;
  else
    _map[z][x] = AObject::POWERUP;
}

int **GameMap::getMap() const
{
  return _map;
}

int GameMap::getHeight() const
{
  return _height;
}

int GameMap::getSpawnX(int id) const {
  return spawPoint[id][0];
}

int GameMap::getSpawnZ(int id) const {
  return spawPoint[id][1];
}
