#include "GameEngine.hpp"

void GameEngine::drawFullMap()
{
  for (int z = 0; z < _height; ++z)
    for (int x = 0; x < _width; ++x)
  	{
  	  if (z >= 0 && x >= 0 )
  	    {
  	      _ground->setPosZ(static_cast<float>(z));
  	      _ground->setPosX(static_cast<float>(x));
  	      _ground->draw(_shader, _clock);
  	    }

  	  if (_map->getCoordType(z, x) == 1 && z >= 0 && x >= 0)
  	    {
  	      _wall->setPosZ(static_cast<float>(z));
  	      _wall->setPosX(static_cast<float>(x));
  	      _wall->draw(_shader, _clock);
  	    }

  	  if (_map->getCoordType(z, x) == 4 && z >= 0 && x >= 0)
  	    {
  	      _block->setPosZ(static_cast<float>(z));
  	      _block->setPosX(static_cast<float>(x));
  	      _block->draw(_shader, _clock);
  	    }

  	  if ((_map->getCoordType(z, x) == 5 ||
	       _map->getCoordType(z, x) == 6) && z >= 0 && x >= 0)
  	    {
  	      _bomb->setPosZ(static_cast<float>(z));
  	      _bomb->setPosX(static_cast<float>(x));
  	      _bomb->draw(_shader, _clock);
  	    }

  	  if (_map->getCoordType(z, x) == 7 && z >= 0 && x >= 0)
  	    {
  	      _explosion->setPosZ(static_cast<float>(z));
  	      _explosion->setPosX(static_cast<float>(x));
  	      _explosion->draw(_shader, _clock);
  	    }

  	  if (_map->getCoordType(z, x) >= 9 && z >= 0 && x >= 0)
  	    {
  	      _bonus[_map->getCoordType(z, x) - 9]->setPosZ(static_cast<float>(z));
  	      _bonus[_map->getCoordType(z, x) - 9]->setPosX(static_cast<float>(x));
  	      _bonus[_map->getCoordType(z, x) - 9]->draw(_shader, _clock);
  	    }
  	}

  for (size_t i = 0; i < _players.size(); ++i)
    if (_players[i]->getDead() == false)
    _players[i]->draw(_shader, _clock);
}

void GameEngine::drawFullScreen()
{
  int player_x = _players[0]->getPosX();
  int player_z = _players[0]->getPosZ();

  for (int z = player_z - 14; z < _height && z < player_z + 14; ++z)
    {
      if (z >= 0)
        for (int x = player_x - 14; x < _width && x < player_x + 14; ++x)
          {
            if (z >= 0 && x >= 0 )
            {
              _ground->setPosZ(static_cast<float>(z));
              _ground->setPosX(static_cast<float>(x));
              _ground->draw(_shader, _clock);
            }

            if (_map->getCoordType(z, x) == 1 && z >= 0 && x >= 0)
            {
              _wall->setPosZ(static_cast<float>(z));
              _wall->setPosX(static_cast<float>(x));
              _wall->draw(_shader, _clock);
            }

            if (_map->getCoordType(z, x) == 4 && z >= 0 && x >= 0)
            {
                _block->setPosZ(static_cast<float>(z));
                _block->setPosX(static_cast<float>(x));
                _block->draw(_shader, _clock);
            }

            if ((_map->getCoordType(z, x) == 5 ||
		 _map->getCoordType(z, x) == 6) && z >= 0 && x >= 0)
            {
                _bomb->setPosZ(static_cast<float>(z));
                _bomb->setPosX(static_cast<float>(x));
                _bomb->draw(_shader, _clock);
            }

            if (_map->getCoordType(z, x) == 7 && z >= 0 && x >= 0)
            {
                _explosion->setPosZ(static_cast<float>(z));
                _explosion->setPosX(static_cast<float>(x));
                _explosion->draw(_shader, _clock);
            }

            if (_map->getCoordType(z, x) >= 9 && z >= 0 && x >= 0)
            {
                _bonus[_map->getCoordType(z, x) - 9]->setPosZ(static_cast<float>(z));
                _bonus[_map->getCoordType(z, x) - 9]->setPosX(static_cast<float>(x));
                _bonus[_map->getCoordType(z, x) - 9]->draw(_shader, _clock);
            }
          }
    }

  for (size_t i = 0; i < _players.size(); ++i)
    if (_players[i]->getDead() == false)
    _players[i]->draw(_shader, _clock);
}

void GameEngine::drawSplitScreen()
{
  for (size_t i = 0; i < 2; ++i)
    {
      int player_x = _players[i]->getPosX();
      int player_z = _players[i]->getPosZ();

      for (size_t j = 0; j < _players.size(); ++j)
	{
	  if (_players[i]->getDead() == false)
	    {
	    _players[j]->draw(_shader, _clock);
	  }
	}

      for (int z = player_z - 14; z < _height && z < player_z + 14; ++z)
	{
	  if (z >= 0)
	    for (int x = player_x - 14; x < _width && x < player_x + 14; ++x)
	      {
		if (z >= 0 && x >= 0 )
		  {
		    _ground->setPosZ(static_cast<float>(z));
		    _ground->setPosX(static_cast<float>(x));
		    _ground->draw(_shader, _clock);
		  }

		if (_map->getCoordType(z, x) == 1 && z >= 0 && x >= 0)
		  {
		    _wall->setPosZ(static_cast<float>(z));
		    _wall->setPosX(static_cast<float>(x));
		    _wall->draw(_shader, _clock);
		  }

		if (_map->getCoordType(z, x) == 4 && z >= 0 && x >= 0)
		  {
		    _block->setPosZ(static_cast<float>(z));
		    _block->setPosX(static_cast<float>(x));
		    _block->draw(_shader, _clock);
		  }

		if ((_map->getCoordType(z, x) == 5 ||
		     _map->getCoordType(z, x) == 6) && z >= 0 && x >= 0)
		  {
		    _bomb->setPosZ(static_cast<float>(z));
		    _bomb->setPosX(static_cast<float>(x));
		    _bomb->draw(_shader, _clock);
		  }

		if (_map->getCoordType(z, x) == 7 && z >= 0 && x >= 0)
		  {
		    _explosion->setPosZ(static_cast<float>(z));
		    _explosion->setPosX(static_cast<float>(x));
		    _explosion->draw(_shader, _clock);
		  }

		if (_map->getCoordType(z, x) >= 9 && z >= 0 && x >= 0)
		  {
		    _bonus[_map->getCoordType(z, x) - 9]->setPosZ(static_cast<float>(z));
		    _bonus[_map->getCoordType(z, x) - 9]->setPosX(static_cast<float>(x));
		    _bonus[_map->getCoordType(z, x) - 9]->draw(_shader, _clock);
		  }
	      }
	}

      if (_players[i]->getDead() == false)
	{
	  _cam = _players[i]->getCamera();

	  _cam->setPosition(glm::vec3(_players[i]->getPosX(),
				      10, _players[i]->getPosZ() - 5));
	  _cam->setCenter(glm::vec3(_players[i]->getPosX(),
				    _players[i]->getPosY(),
				    _players[i]->getPosZ()));

	  _projection = _cam->setPerspective((_winX / 2), _winY);
	  _transformation = _cam->setLookAt();

	  // The shader always needs to be bound before setUniform method calls
	  _shader.bind();
	  _shader.setUniform("view", _transformation);
	  _shader.setUniform("projection", _projection);

	  // horizontal
	  glViewport((_winX / 2) * i, 0, _winX / 2, _winY);
	}
    }
}
