#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <string>
#include <iostream> // debug
#include <fmod.h> // FMOD Ex

#include "Exception.hpp"

class Sound
{
private:
  bool isOn;
  bool possible;
  std::string currentSound;

  // FMOD-specific stuff
  FMOD_RESULT result;
  FMOD_SYSTEM *fmodsystem;
  FMOD_SOUND *sound;
  FMOD_CHANNEL *channel;

public:
  Sound();
  ~Sound();

  void initialise(void);

  // sound control methods
  void setVolume(float v);
  void load(const std::string &filename);
  void unload(void);

  // plays a sound (can be started paused; no argument for unpaused)
  void play(bool pause = false);

  // check if the sound is on
  bool getSound(void);

  // turn the sound on/off
  void setSound(bool sound);

  // pause/unpause the sound
  void setPause(bool pause);

  // toggles on/off
  void toggleSound(void);

  // toggles pause/unpause
  void togglePause(void);

};

#endif
