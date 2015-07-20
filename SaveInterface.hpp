#include <SdlContext.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <Input.hh>
#include <Game.hh>
#include <SDL_keycode.h>

#include "Texture.hh"
#include "Geometry.hh"
#include "AObject.hpp"

class SaveInterface : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  int _pos;
  int _position;
  int		_option;
  size_t option;
  bool setting;
  std::map<int, std::string> _path;
  std::string winner;
  char _letter;

public:
  SaveInterface(int Px, int Py, int Pz, int Rx, int Ry, int Rz, std::map<int, std::string> path) : AObject(Px, Py, Pz, Rx, Ry ,Rz){ _path = path;}
  virtual ~SaveInterface() { }

  virtual bool initialize()
  {
    _letter = 'a';
    _speed = 10.0f;
    setting = false;
    _pos = 0;
    _position = 0;
    if (_texture.load(_path[SDLK_a]) == false)
      return (false);
    _geometry.pushVertex(glm::vec3(3, -3, 3));
    _geometry.pushVertex(glm::vec3(3, 3, 3));
    _geometry.pushVertex(glm::vec3(-3, 3, 3));
    _geometry.pushVertex(glm::vec3(-3, -3, 3));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
  }

  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    static_cast<void>(clock);
    if (input.getKey(SDLK_ESCAPE))
      exit(0);
    else
      catchKey(input);
  }

  void catchKey(gdl::Input &input)
  {
    int i;

    i = 0;
    for (std::map<int, std::string>::iterator it = _path.begin();
	 it != _path.end(); ++it)
      {
        if (input.getKey((*it).first, true))
	  {
	    _texture.load((*it).second);
	    _letter = (i + 97);
	  }
	else
	  i++;
      }
  }

  virtual bool getSetting()
  {
    AObject::setSetting(setting);
    return setting;
  }

  virtual int getPosition()
  {
    return _position;
  }

  virtual void setSetting(bool _setting)
  {
    setting = _setting;
  }

  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock)
  {
    static_cast<void>(clock);
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
  }

  virtual char getLetter() const
  {
    return _letter;
  }
};
