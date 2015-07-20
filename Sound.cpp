#include "Sound.hpp"

Sound::Sound()
{

}

Sound::~Sound()
{
  FMOD_Sound_Release(sound);
}

void Sound::initialise(void)
{
  // create the sound system : if it fails, sound is set to impossible
  result = FMOD_System_Create(&fmodsystem);
  if (result != FMOD_OK)
    possible = false;

  // initialize the sound system : if it fails, sound is set to impossible
  if (possible)
    result = FMOD_System_Init(fmodsystem, 2, FMOD_INIT_NORMAL, 0);
  if (result != FMOD_OK)
    possible = false;

  // sets initial sound volume (mute)
  if (possible)
    FMOD_Channel_SetVolume(channel, 0.0f);
}

void Sound::setVolume(float v)
{
  if (possible && isOn && v >= 0.0f && v <= 1.0f)
    FMOD_Channel_SetVolume(channel, v);
}

void Sound::load(const std::string &filename)
{
  currentSound = filename;
  if (possible && isOn)
    {
      result = FMOD_Sound_Release(sound);
      result = FMOD_System_CreateStream(fmodsystem, currentSound.c_str(),
					FMOD_SOFTWARE, 0, &sound);
      if (result != FMOD_OK)
	possible = false;
    }
}

void Sound::unload(void)
{
  if (possible)
    result = FMOD_Sound_Release(sound);
}

// plays a sound (can be started paused; no argument for unpaused)
void Sound::play(bool pause)
{
  if (possible && isOn)
    {
      result = FMOD_System_PlaySound(fmodsystem, FMOD_CHANNEL_FREE, sound,
				     pause, &channel);
      FMOD_Channel_SetMode(channel, FMOD_LOOP_NORMAL);
    }
}

// check if the sound is on
bool Sound::getSound(void)
{
  return isOn;
}

// turn the sound on/off
void Sound::setSound(bool s)
{
  isOn = s;
}

// pause/unpause the sound
void Sound::setPause(bool pause)
{
  FMOD_Channel_SetPaused(channel, pause);
}

// toggles on/off
void Sound::toggleSound(void)
{
  isOn = !isOn;
  if (isOn == true)
    {
      load(currentSound);
      play();
    }
  if (isOn == false)
    unload();
}

// toggles pause/unpause
void Sound::togglePause(void)
{
  FMOD_BOOL p;

  FMOD_Channel_GetPaused(channel, &p);
  FMOD_Channel_SetPaused(channel, !p);
}
