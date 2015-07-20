#include "GameEngine.hpp"

bool GameEngine::HomeMode()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    {
      _objects[i]->update(_clock, _input, mode);
    }
  if (_objects[0]->getSetting() == true)
    {
      if (mode == "home")
        {
	  switch(_objects[0]->getPosition())
	    {
            case 0:
	      {
		mode = "setting";
		if (loadSetting() == false)
		  throw ErrorException("setting load failed in CreateMenu.cpp");
		stat++;
		break;
	      }
            case 1:
	      {
		// pos = 1;
		// mode = "load";
		// createLoad();
		break;
	      }
            case 2:
	      std::cout << "bye" << std::endl;
	      return false;
	      break;
	    }
        }
      if (mode == "setting")
        {
          SettingMode();
        }
    }
  return true;
}

bool GameEngine::SettingMode()
{
  if (_objects[0]->getSetting() == true)
    {
      _objects[0]->setSetting(false);
      if (stat > 3)
	{
	  mode = "play";
	  _positionHome.push_back(_objects[0]->getPosition());
	  clearVector();
	  stat = 0;
	  _players.clear();
	  _objects.clear();
	  startGame();
	  return true;
	}
      else
	{
	  _positionHome.push_back(_objects[0]->getPosition());
	  clearVector();
	  if (stat > 2 && (_objects[0]->getPosition() == 0))
	    {
	      if (loadSetting() == false)
		throw ErrorException("setting load failed in CreateMenu.cpp");
	      stat++;
	    }
	  else if (stat > 2 && (_objects[0]->getPosition() == 1))
	    {
	      mode = "custom";
	      pos = 1;
	      stat = 4;
	      if (loadSetting() == false)
		      throw ErrorException("setting load failed in CreateMenu.cpp");
	    }
	  else
	    {
	      if (loadSetting() == false)
		      throw ErrorException("setting load failed in CreateMenu.cpp");
	      stat++;
	    }
	}
    }
  return true;
}

bool GameEngine::PauseMode()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    {
      _objects[i]->update(_clock, _input, mode);
    }
  if (_objects[0]->getSetting() == true)
    {
      switch(_objects[0]->getPosition())
	{
        case 0:
	  {
	    // resume
	    _objects = _tmp;
	    mode = "play";
	    if (_positionHome.at(0) == 1)
	      _splitScreen = true;
	    clearVector();
	    break;
	  }
        case 1:
          {
            //save file
            mode = "save";
            pos = 1;
            saveGame();
            break;
          }
        case 2:
	  _positionHome.clear();
          mainMenu();
          break;
	}
    }
  return true;
}

bool GameEngine::ScoreMode()
{
  if (_input.getKey(SDLK_RETURN, true))
  {
    mode = "over";
    loadWinner2();
    return true;
  }
  for (size_t i = 0; i < _objects.size(); ++i)
    {
      _objects[i]->update(_clock, _input, mode);
    }
  return true;
}

bool GameEngine::OverMode()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    {
      _objects[i]->update(_clock, _input, mode);
    }
  if(_objects[0]->getPosition() != -1)
    {
      mode = "play";
      startGame();
    }
  return true;
}

bool GameEngine::SaveMode()
{
  if (_input.getKey(SDLK_LEFT))
    {
      if (pos > 1)
        pos--;
      _objects[0]->update(_clock, _input);
    }
  if (_input.getKey(SDLK_RIGHT))
    {
      if (pos < 4)
        pos++;
      _objects[0]->update(_clock, _input);
    }
  if (_input.getKey(SDLK_ESCAPE))
    {
      exit(0);
    }
  _objects[pos]->update(_clock, _input);
  std::stringstream tmp;
  int i = 0;
  for (std::vector<AObject *>::iterator it = _objects.begin(); it != _objects.end(); it++)
    {
      if (i > 0)
	tmp << (*it)->getLetter();
      i = 1;
    }
  if (_input.getKey(SDLK_RETURN, true))
    {
      Save save;
      tmp << ".save";
      save.saveFile(tmp.str(), _width, _height, _players, _map->getMap(), _positionHome);
      mode = "pause";
      createPause();
    }
  return true;
}

bool GameEngine::loadMode()
{
  if (_input.getKey(SDLK_RETURN, true))
    {
      mode = "pause";
    }
  if (_input.getKey(SDLK_LEFT))
    {
      if (pos > 1)
        pos--;
      _objects[0]->update(_clock, _input);
    }
  if (_input.getKey(SDLK_RIGHT))
    {
      if (pos < 4)
        pos++;
      _objects[0]->update(_clock, _input);
    }
  _objects[pos]->update(_clock, _input);
  return true;
}

bool GameEngine::CustomMode()
{
  if (_input.getKey(SDLK_RETURN, true))
    {
      mode = "play";
      stat = 0;

      size_t j = 1000;

      _total = 0;
      for (size_t i = 1; i < _objects.size(); ++i)
	{
	  if (_objects[i]->getNbValue() == 9)
	    {
	      _total += 0 * j;
	    }
	  else
	    _total += (_objects[i]->getNbValue() + 1) * j;
	  j /= 10;
	}
      if (_total < 10)
	_total = 10;
      clearVector();
      _players.clear();
      startGame();
      return true;
    }
  if (_input.getKey(SDLK_LEFT))
    {
      if (pos > 1)
        pos--;
      _objects[0]->update(_clock, _input);
    }
  if (_input.getKey(SDLK_RIGHT))
    {
      if (pos < 4)
        pos++;
      _objects[0]->update(_clock, _input);
    }
  _objects[pos]->update(_clock, _input);
  return true;
}

bool GameEngine::PlayMode()
{
  if (_input.getKey(SDLK_ESCAPE, true))
    {
      mode = "pause";
      _splitScreen = false;
      _cam->setPosition(glm::vec3(0, 0, 3));
      _cam->setCenter(glm::vec3(0, 0, 0));
      _projection = _cam->setPerspective(_winX, _winY);
      _transformation = _cam->setLookAt();
      _shader.bind();
      _shader.setUniform("view", _transformation);
      _shader.setUniform("projection", _projection);
      _tmp = _objects;
      stat = 5;
      if (loadSetting() == false)
	throw ErrorException("setting load failed in CreateMenu.cpp");
      return true;
    }
  unsigned int	nb_dead = 0;

  // The projection of the camera corresponds to the way
  // the objects will be drawn on screen
  if (_width < 25 && _height < 25)
    {
      _cam->setPosition(glm::vec3(_width / 2,
				  (_width + _height) / 2, _height / 2 - 1));
      _cam->setCenter(glm::vec3(_width / 2,
				_players[0]->getPosY(),
				_height / 2));
    }
  else if (!_splitScreen)
    {
      _cam->setPosition(glm::vec3(_players[0]->getPosX(),
				  10, _players[0]->getPosZ() - 5));
      _cam->setCenter(glm::vec3(_players[0]->getPosX(),
				_players[0]->getPosY(),
				_players[0]->getPosZ()));
    }

  if ((_width < 25 && _height < 25) || !_splitScreen)
    {
      _projection = _cam->setPerspective(_winX, _winY);
      _transformation = _cam->setLookAt();

      // The shader always needs to be bound before setUniform method calls
      _shader.bind();
      _shader.setUniform("view", _transformation);
      _shader.setUniform("projection", _projection);
    }

  // If the ESCAPE key is pressed or if the user close the window
  // Then the program exits
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;

  for (size_t i = 0; i < _players.size(); ++i)
    if (_players[i]->getDead() == false)
      _players[i]->movePlayer(_clock, _input);
    else
      ++nb_dead;

  if (nb_dead == _players.size() - 1)
    {
      for (size_t i = 0; i < _players.size(); ++i)
        if (_players[i]->getDead() == false)
	  {
	    mode = "score";
	    loadWinner();
      _id = i + 1;
	  }
      return true;
    }
  else if (nb_dead == _players.size())
    {
      mode = "score";
      loadWinner();
      _id = 0;
      return true;
    }

  for (size_t i = 0; i < _dynamicObjects.size(); ++i)
    {
      if (_dynamicObjects[i]->getState() == AObject::TODESTROY && i == _dynamicObjects.size() - 1)
      	{
      	  delete _dynamicObjects[i];
      	  _dynamicObjects.pop_back();
      	}
      else
      	_dynamicObjects[i]->update(_clock, _input, _dynamicObjects);
    }

  // FPS Info display
  static float time = 0;
  static int fps = 0;

  fps++;
  time += _clock.getElapsed();
  if (time >= 1)
    {
      time = 0;
      fps = 0;
    }
  return true;
}
