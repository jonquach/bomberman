#include "GameEngine.hpp"

std::vector<std::string> GameEngine::createHomeSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/start.tga");
  tmp.push_back("./img/load.tga");
  tmp.push_back("./img/exit.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createWinnerSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/winnerTie.tga");
  tmp.push_back("./img/winner1.tga");
  tmp.push_back("./img/winner2.tga");
  tmp.push_back("./img/winnerComputer.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createPlayerSettingSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/SettingPlayer2.tga");
  tmp.push_back("./img/MenuSetting/SettingPlayer3.tga");
  tmp.push_back("./img/MenuSetting/SettingPlayer4.tga");
  tmp.push_back("./img/MenuSetting/SettingPlayer5.tga");
  tmp.push_back("./img/MenuSetting/SettingPlayer6.tga");
  tmp.push_back("./img/MenuSetting/SettingPlayer7.tga");
  tmp.push_back("./img/MenuSetting/SettingPlayer8.tga");
  return tmp;
}

std::map<int, std::string> GameEngine::createAlphabetSlide()
{
  std::map<int, std::string> tmp;
  tmp[SDLK_a] = "./letters/alphabet_01.tga";
  tmp[SDLK_b] = "./letters/alphabet_03.tga";
  tmp[SDLK_c] = "./letters/alphabet_05.tga";
  tmp[SDLK_d] = "./letters/alphabet_07.tga";
  tmp[SDLK_e] = "./letters/alphabet_09.tga";
  tmp[SDLK_f] = "./letters/alphabet_11.tga";
  tmp[SDLK_g] = "./letters/alphabet_13.tga";
  tmp[SDLK_h] = "./letters/alphabet_15.tga";
  tmp[SDLK_i] = "./letters/alphabet_17.tga";
  tmp[SDLK_j] = "./letters/alphabet_27.tga";
  tmp[SDLK_k] = "./letters/alphabet_28.tga";
  tmp[SDLK_l] = "./letters/alphabet_29.tga";
  tmp[SDLK_m] = "./letters/alphabet_31.tga";
  tmp[SDLK_n] = "./letters/alphabet_32.tga";
  tmp[SDLK_o] = "./letters/alphabet_33.tga";
  tmp[SDLK_p] = "./letters/alphabet_34.tga";
  tmp[SDLK_q] = "./letters/alphabet_36.tga";
  tmp[SDLK_r] = "./letters/alphabet_38.tga";
  tmp[SDLK_s] = "./letters/alphabet_49.tga";
  tmp[SDLK_t] = "./letters/alphabet_50.tga";
  tmp[SDLK_u] = "./letters/alphabet_51.tga";
  tmp[SDLK_v] = "./letters/alphabet_52.tga";
  tmp[SDLK_w] = "./letters/alphabet_54.tga";
  tmp[SDLK_x] = "./letters/alphabet_56.tga";
  tmp[SDLK_y] = "./letters/alphabet_57.tga";
  tmp[SDLK_z] = "./letters/alphabet_58.tga";
  return tmp;
}

std::vector<std::string> GameEngine::createModeSettingSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/SettingSolo.tga");
  tmp.push_back("./img/MenuSetting/SettingMulti.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createPauseSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/PauseResume.tga");
  tmp.push_back("./img/MenuSetting/PauseSave.tga");
  tmp.push_back("./img/MenuSetting/PauseMainMenu.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createMapSettingSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/SettingPredefined.tga");
  tmp.push_back("./img/MenuSetting/SettingCustom.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createPredefinedSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/Predefined3.tga");
  tmp.push_back("./img/MenuSetting/Predefined1.tga");
  tmp.push_back("./img/MenuSetting/Predefined2.tga");
  tmp.push_back("./img/MenuSetting/Predefined4.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createScoreSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/2player.tga");
  tmp.push_back("./img/3player.tga");
  tmp.push_back("./img/4player.tga");
  tmp.push_back("./img/5player.tga");
  tmp.push_back("./img/6player.tga");
  tmp.push_back("./img/7player.tga");
  tmp.push_back("./img/8player.tga");
  tmp.push_back("./img/9player.tga");
  tmp.push_back("./img/10player.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createCustomSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/Custom2.tga");
  return tmp;
}

std::map<int, std::string> GameEngine::createNumbersSlide()
{
  std::map<int, std::string> tmp;
  tmp[SDLK_KP_0] = ("./numbers/0.tga");
  tmp[SDLK_KP_1] = ("./numbers/1.tga");
  tmp[SDLK_KP_2] = ("./numbers/2.tga");
  tmp[SDLK_KP_3] = ("./numbers/3.tga");
  tmp[SDLK_KP_4] = ("./numbers/4.tga");
  tmp[SDLK_KP_5] = ("./numbers/5.tga");
  tmp[SDLK_KP_6] =("./numbers/6.tga");
  tmp[SDLK_KP_7] = ("./numbers/7.tga");
  tmp[SDLK_KP_8] = ("./numbers/8.tga");
  tmp[SDLK_KP_9] =("./numbers/9.tga");
  return tmp;
}

std::vector<std::string> GameEngine::createRoundSettingSlide()
{
  std::vector<std::string> tmp;
  tmp.push_back("./img/MenuSetting/life.tga");
  tmp.push_back("./img/MenuSetting/2player.tga");
  tmp.push_back("./img/MenuSetting/map3.tga");
  return tmp;
}
