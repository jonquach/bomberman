#include "Texture.hh"
#include "Geometry.hh"
#include "AObject.hpp"

#ifndef		BUTTON_HPP_
# define	BUTTON_HPP_

class Button : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  int _pos;
  std::string _path;

public:
  Button(int Px, int Py, int Pz, int Rx, int Ry, int Rz,
	 std::string const &pt);
  virtual ~Button() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual char getLetter() const;
};


#endif
