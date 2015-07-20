#include "GameEngine.hpp"

GameEngine::GameEngine() : _winX(1024), _winY(768)
{
  mode = "home";
  nb = 0;
  pos = 0;
  stat = 0;
}

GameEngine::~GameEngine()
{
  if (mode == "play")
    {
      delete _wall;
      for (size_t i = 0; i < _players.size(); ++i)
	delete _players[i];
      if (_cam != NULL)
	delete _cam;
    }
}


bool GameEngine::initialize()
{
  tab[0] = &GameEngine::createModeSetting;
  tab[1] = &GameEngine::createPlayerSetting;
  tab[2] = &GameEngine::createMapModeSetting;
  tab[3] = &GameEngine::createPredefinedSetting;
  tab[4] = &GameEngine::createCustomSetting;
  tab[5] = &GameEngine::createPause;

  if (!_context.start(_winX, _winY, "Bomberman"))
    return false;
  std::cout << "WINDOW CREATED" << std::endl;

  glEnable(GL_DEPTH_TEST);
  std::cout << "GLENABLE IS GOOD" << std::endl;

  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER))
    throw ErrorException("Error : shader load basic.fp failed in GameEnigne.cpp");
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER))
    throw ErrorException("Error : shader load basic.vp failed in GameEnigne.cpp");
  if (!_shader.build())
    throw ErrorException("Error : shader build failed in GameEnigne.cpp");
  std::cout << "SHADER LOAD + SHADER BUILD IS GOOD" << std::endl;

  _cam = new Camera(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0));
  _projection = _cam->setPerspective(_winX, _winY);
  _transformation = _cam->setLookAt();

  // The shader always needs to be bound before setUniform method calls
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);

  createSound();
  createHomeMenu();
  return true;
}

bool GameEngine::update()
{
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  if (mode == "over")
    return (OverMode());
  if (mode == "home" || mode == "setting")
    return (HomeMode());
  if (mode == "pause")
    return (PauseMode());
  if (mode == "save")
    return (SaveMode());
  if (mode == "custom")
    return(CustomMode());
  if (mode == "play")
    return (PlayMode());
  if (mode == "load")
    return (loadMode());
  if (mode == "score")
    return (ScoreMode());
  return false;
}

bool GameEngine::loadSetting()
{
  return ((this->*tab[stat])());
}

void GameEngine::clearVector()
{
  _objects.clear();
}

void GameEngine::draw()
{
  if (mode == "play")
  {
     // Clear the screen
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // To use a shader (so it can draw the geometry), it must bind
      // Only one shader can be active at the same time
      _shader.bind();

      // We draw all objects which compose the scene
      if (_width < 25 && _height < 25)
        drawFullMap();
      else if (_splitScreen)
        drawSplitScreen();
      else
        drawFullScreen();

      // We update the screen so it displays what is on screen
      _context.flush();
  }
  else
  {
    glViewport(0, 0, _winX, _winY);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _shader.bind();
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);
    _context.flush();
  }
}
