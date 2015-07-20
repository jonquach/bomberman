#include <Game.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <Input.hh>

#include "AObject.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Slide : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  int _pos;
  int position;
  int		_option;
  size_t option;
  bool setting;
  std::vector<std::string> _path;
  std::string winner;

public:
  Slide(int Px, int Py, int Pz, int Rx, int Ry, int Rz, std::vector<std::string> path, int option) : AObject(Px, Py, Pz, Rx, Ry ,Rz){ _path = path; _option = option;
  }
  virtual ~Slide() { }

  virtual bool initialize()
  {
    _speed = 10.0f;
    setting = false;
    _pos = 0;
    if (_texture.load(_path.at(_option)) == false)
      return (false);

    _geometry.pushVertex(glm::vec3(45, -45, 45));
    _geometry.pushVertex(glm::vec3(45, 45, 45));
    _geometry.pushVertex(glm::vec3(-45, 45, 45));
    _geometry.pushVertex(glm::vec3(-45, -45, 45));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
  }

  virtual void update(gdl::Clock const &clock, gdl::Input &input, std::string mode)
  {
    static_cast<void>(clock);
    if (input.getKey(SDLK_ESCAPE, true))
      exit(0);
    if (mode != "over")
      {
	// left
	if (input.getKey(SDLK_LEFT,true))
	  {
	    if (_pos > 0)
	      _pos--;
	    _texture.load(_path.at(_pos));
	  }

	// right
	if (input.getKey(SDLK_RIGHT, true))
	  {
	    if (_pos < (int)_path.size() - 1)
	      _pos++;
	    _texture.load(_path.at(_pos));
	  }

	// enter
	if (input.getKey(SDLK_RETURN, true))
	  {
	    position = _pos;
	    setting = true;
	  }
      }
    else
      {
	// enter
	if (input.getKey(SDLK_RETURN, true))
	  {
	    position = 1;
	  }
	else
	  {
	    position = -1;
	  }
      }
  }
  virtual bool getSetting()
  {
    AObject::setSetting(setting);
    return setting;
  }

  virtual int getPosition()
  {
    return position;
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
