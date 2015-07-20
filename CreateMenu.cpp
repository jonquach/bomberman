#include "GameEngine.hpp"

bool GameEngine::createHomeMenu()
{
  std::vector<std::string> _home = createHomeSlide();
  AObject *button = new  Slide(0, -10, -100, 0, 0, 270, _home, 0);
  if ((button->initialize() == false))
    return (false);
  _objects.push_back(button);
  return (true);
}

bool GameEngine::createModeSetting()
{
  clearVector();
  std::vector<std::string> _mode = createModeSettingSlide();
  AObject *mode = new Slide(0, -10, -100, 0, 0, 270, _mode, 0);
  if ((mode->initialize() == false))
    return (false);
  _objects.push_back(mode);
  return (true);
}

bool GameEngine::createPlayerSetting()
{
  clearVector();
  std::vector<std::string> _player = createPlayerSettingSlide();
  AObject *player = new Slide(0, -10, -100, 0, 0, 270, _player, 0);
  if ((player->initialize() == false))
    return (false);
  _objects.push_back(player);
  return (true);
}

bool GameEngine::createMapModeSetting()
{
  clearVector();
  std::vector<std::string> _mapMode = createMapSettingSlide();
  AObject *mapMode = new Slide(0, -10, -100, 0, 0, 270, _mapMode, 0);
  if ((mapMode->initialize() == false))
    return (false);
  _objects.push_back(mapMode);
  return (true);
}

bool GameEngine::createPredefinedSetting()
{
  clearVector();
  std::vector<std::string> _predefined = createPredefinedSlide();
  AObject *predefined = new Slide(0, -10, -100, 0, 0, 270, _predefined, 0);
  if ((predefined->initialize() == false))
    return (false);
  _objects.push_back(predefined);
  return (true);
}

bool GameEngine::createCustomSetting()
{
  clearVector();
  std::vector<std::string> _custom = createCustomSlide();
  std::map<int, std::string> _numbers = createNumbersSlide();
  AObject *arrow = new Arrow(-8, -6, -70, 0, 0, 270, "./img/arrowUp.tga");
  AObject *number1 = new Number(-8, 0, -70, 0, 0, 270, _numbers);
  AObject *number2 = new Number(-2, 0, -70, 0, 0, 270, _numbers);
  AObject *number3 = new Number(4, 0, -70, 0, 0, 270, _numbers);
  AObject *number4 = new Number(10, 0, -70, 0, 0, 270, _numbers);
  if ((arrow->initialize() == false) || (number1->initialize() == false)
      || (number2->initialize() == false) || (number3->initialize() == false)
      || (number4->initialize() == false))
    return (false);
  _objects.push_back(arrow);
  _objects.push_back(number1);
  _objects.push_back(number2);
  _objects.push_back(number3);
  _objects.push_back(number4);
  return (true);
}

bool GameEngine::createPause()
{
  clearVector();
  _cam->setPosition(glm::vec3(0, 0, 3));
  _cam->setCenter(glm::vec3(0, 0, 0));
  _projection = _cam->setPerspective(_winX, _winY);
  _transformation = _cam->setLookAt();

  // The shader always needs to be bound before setUniform method calls
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);
  std::vector<std::string> _pause = createPauseSlide();
  AObject *pause = new Slide(0, -10, -100, 0, 0, 270, _pause, 0);
  if ((pause->initialize() == false))
    return (false);
  _objects.push_back(pause);
  return (true);
}

void GameEngine::createSound()
{
  _sound = new Sound();
  _sound->initialise();
  _sound->load("./music/08-bgm-08.mp3");
  _sound->play();
}

bool GameEngine::startGame()
{
  _cam->setPosition(glm::vec3(0, 0, 0));
  _cam->setCenter(glm::vec3(0, 10, 10));
  _projection = _cam->setPerspective(_winX, _winY);
  _transformation = _cam->setLookAt();

  // The shader always needs to be bound before setUniform method calls
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);

  _height = _total;
  _width = _height;
  if (_height % 2 == 0)
    ++_height;
  if (_width % 2 == 0)
    ++_width;
  _map = new GameMap(_width, _height, _dynamicObjects);

  if (_positionHome.at(2) == 1)
    {
      _map->createCustomMap();
    }
  else
    {
      _height = 23;
      _width = 23;
      _map->createMap(_positionHome.at(3));
    }

  int nb_player = _positionHome.at(1) + 2;

  for (int i = 0; i < nb_player; ++i)
    {
      Player *p;
      p = new Player(*_map);
      _players.push_back(p);
      if (_positionHome.at(0) == 0 && i > 0)
	{
	  if (p->initCharacter(_dynamicObjects, i + 2) == false)
	    throw ErrorException("Error : player load failed in Player.cpp");
	}
      else
	if (p->initCharacter(_dynamicObjects, i + 1) == false)
	  throw ErrorException("Error : player load failed in Player.cpp");
    }

  // Will be set by the menu
  if (_positionHome.at(0) == 1)
    _splitScreen = true;
  else
    _splitScreen = false;

  // initializing objects
  int nbBomb = 0;
  _wall = new Cube;
  _block = new Block;
  _ground = new Ground;
  _bomb = new Bomb(*_map, nbBomb);
  _explosion = new Explosion;
  if (_wall->initialize() == false)
    throw ErrorException("Error : texture load failed in Cube.hpp");
  if (_block->initialize() == false)
    throw ErrorException("Error : texture load failed in Block.hpp");
  if (_ground->initialize() == false)
    throw ErrorException("Error : texture load failed in Ground.hpp");
  if (_bomb->initialize() == false)
    throw ErrorException("Error : texture load failed in Bomb.cpp");
  if (_explosion->initialize() == false)
    throw ErrorException("Error : texture load failed in Explosion.cpp");
  _wall->setPosZ(1.0f);
  _wall->setPosX(1.0f);
  _block->setPosZ(1.0f);
  _block->setPosX(1.0f);
  _ground->setPosZ(1.0f);
  _ground->setPosX(1.0f);

  // initializing bonuses
  Bonus *bonus = new Bonus(AObject::BOMBUP);
  if (bonus->initialize() == false)
    throw ErrorException("Error : texture load failed in Bonus.cpp");
  _bonus.push_back(bonus);

  bonus = new Bonus(AObject::POWERUP);
  if (bonus->initialize() == false)
    throw ErrorException("Error : texture load failed in Bonus.cpp");
  _bonus.push_back(bonus);

  bonus = new Bonus(AObject::SPEEDUP);
  if (bonus->initialize() == false)
    throw ErrorException("Error : texture load failed in Bonus.cpp");
  _bonus.push_back(bonus);

  return (true);
}

void GameEngine::mainMenu()
{
  mode = "home";
  stat = 0;
  clearVector();
  _players.clear();
  _cam->setPosition(glm::vec3(0, 0, 3));
  _cam->setCenter(glm::vec3(0, 0, 0));
  _projection = _cam->setPerspective(_winX, _winY);
  _transformation = _cam->setLookAt();

  // The shader always needs to be bound before setUniform method calls
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);
  createHomeMenu();
}

bool GameEngine::saveGame()
{
  clearVector();
  std::map<int, std::string> _alphabet = createAlphabetSlide();
  AObject *arrow = new Arrow(-8, -6, -70, 0, 0, 270, "./img/arrowUp.tga");
  AObject *alphabet1 = new SaveInterface(-8, 0, -70, 0, 0, 270, _alphabet);
  AObject *alphabet2 = new SaveInterface(-2, 0, -70, 0, 0, 270, _alphabet);
  AObject *alphabet3 = new SaveInterface(4, 0, -70, 0, 0, 270, _alphabet);
  AObject *alphabet4 = new SaveInterface(10, 0, -70, 0, 0, 270, _alphabet);
  if ((arrow->initialize() == false) || (alphabet1->initialize() == false)
      || (alphabet2->initialize() == false)
      || (alphabet3->initialize() == false)
      || (alphabet4->initialize() == false))
    return (false);
  _objects.push_back(arrow);
  _objects.push_back(alphabet1);
  _objects.push_back(alphabet2);
  _objects.push_back(alphabet3);
  _objects.push_back(alphabet4);
  return (true);

}

bool GameEngine::createLoad()
{
  clearVector();
  std::map<int, std::string> _alphabet = createAlphabetSlide();
  AObject *arrow = new Arrow(-8, -6, -70, 0, 0, 270, "./img/arrowUp.tga");
  AObject *alphabet1 = new SaveInterface(-8, 0, -70, 0, 0, 270, _alphabet);
  AObject *alphabet2 = new SaveInterface(-2, 0, -70, 0, 0, 270, _alphabet);
  AObject *alphabet3 = new SaveInterface(4, 0, -70, 0, 0, 270, _alphabet);
  AObject *alphabet4 = new SaveInterface(10, 0, -70, 0, 0, 270, _alphabet);
  if ((arrow->initialize() == false) || (alphabet1->initialize() == false)
      || (alphabet2->initialize() == false)
      || (alphabet3->initialize() == false)
      || (alphabet4->initialize() == false))
    return (false);
  _objects.push_back(arrow);
  _objects.push_back(alphabet1);
  _objects.push_back(alphabet2);
  _objects.push_back(alphabet3);
  _objects.push_back(alphabet4);
  return (true);
}

bool GameEngine::loadWinner()
{
  clearVector();
  _players.clear();
  _dynamicObjects.clear();
  _cam->setPosition(glm::vec3(0, 0, 3));
  _cam->setCenter(glm::vec3(0, 0, 0));
  _projection = _cam->setPerspective(_winX, _winY);
  _transformation = _cam->setLookAt();

  // The shader always needs to be bound before setUniform method calls
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);
  std::vector<std::string> _winner = createWinnerSlide();
  std::vector<std::string> _score = createScoreSlide();
  std::map<int, std::string> _numbers = createNumbersSlide();
  AObject *score = new Slide(0, 0, -120, 0, 0, 270, _score, _positionHome.at(1) - 1);
  if ((score->initialize() == false))

    return (false);
  _objects.push_back(score);
  return (true);
}
bool GameEngine::loadWinner2()
{
  clearVector();

  // The shader always needs to be bound before setUniform method calls
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);
  std::vector<std::string> _winner = createWinnerSlide();
  AObject *winner = new Slide(0, -10, -120, 0, 0, 270, _winner, _id);
  if ((winner->initialize() == false))
    return (false);
  _objects.push_back(winner);
  return (true);
}

