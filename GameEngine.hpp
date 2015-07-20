#pragma once
// gdl
#include <Game.hh>
#include <SdlContext.hh>
#include <SDL_keycode.h>
#include <BasicShader.hh>

// stl
#include <vector>
#include <iostream>
#include <sstream>

// ours
#include "AObject.hpp"
#include "Texture.hh"
#include "Geometry.hh"
#include "Background.hpp"
#include "Button.hpp"
#include "Character.hpp"
#include "Exception.hpp"
#include "Camera.hpp"
#include "Sound.hpp"
#include "Cube.hpp"
#include "Player.hpp"
#include "Ground.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
#include "Explosion.hpp"
#include "Bonus.hpp"
#include "GameMap.hh"
#include "number.hpp"
#include "Arrow.hpp"
#include "Slide.hpp"
#include "SaveInterface.hpp"
#include "Save.hpp"

class GameEngine : public gdl::Game
{
private:
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  gdl::Texture _texture;

  std::vector<Bonus *> _bonus;
  AObject * _wall;
  AObject * _ground;
  AObject * _block;
  AObject * _bomb;
  AObject * _explosion;
  std::vector<Player*> _players;
  GameMap	*_map;
  int _winX;
  int _winY;
  glm::mat4 _projection;
  glm::mat4 _transformation;
  Camera *_cam;
  Sound *_sound;
  int _height;
  int _width;
  std::deque<Bomb *> _dynamicObjects;
  bool _splitScreen;
  int	_total;

  typedef bool(GameEngine::*setting)();
  setting tab[6];
  std::vector<AObject*> _objects;
  std::vector<AObject*> _tmp;
  std::vector<int> _positionHome;
  int stat;
  std::string mode;
  int pos;
  int nb;
  double  old_time;
  int _id;

  std::list<char> _saveTitle;

public:
  GameEngine();
  ~GameEngine();

public:
  bool initialize();
  bool update();
  void draw();
  void drawFullScreen();
  void drawFullMap();
  void drawSplitScreen();

  bool createHomeMenu();
  void clearVector();
  void createSound();
  bool startGame();

  // Pause
  void mainMenu();
  bool saveGame();
  bool loadMode();

  // Slide images
  std::vector<std::string> createPlayerSettingSlide();
  std::vector<std::string> createModeSettingSlide();
  std::vector<std::string> createRoundSettingSlide();
  std::vector<std::string> createMapSettingSlide();
  std::vector<std::string> createHomeSlide();
  std::vector<std::string> createPauseSlide();
  std::vector<std::string> createWinnerSlide();
  std::map<int, std::string> createAlphabetSlide();
  std::vector<std::string> createPredefinedSlide();
  std::vector<std::string> createCustomSlide();
  std::map<int, std::string> createNumbersSlide();
  std::vector<std::string> createScoreSlide();

  // Setting
  bool createModeSetting();
  bool createPlayerSetting();
  bool createMapModeSetting();
  bool createPredefinedSetting();
  bool createPause();
  bool loadSetting();
  bool createCustomSetting();
  bool createLoad();

  // winner
  bool loadWinner();
  bool loadWinner2();

  // mode
  bool HomeMode();
  bool SettingMode();
  bool PauseMode();
  bool OverMode();
  bool PlayMode();
  bool SaveMode();
  bool CustomMode();
  bool ScoreMode();
};
