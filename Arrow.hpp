#include <Game.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <Input.hh>
#include "Texture.hh"
#include "Geometry.hh"
#include "AObject.hpp"

#ifndef		ARROW_HPP_
# define        ARROW_HPP_

class Arrow : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  std::string _path;
  int pos;

public:
  Arrow(int Px, int Py, int Pz, int Rx, int Ry, int Rz,
	std::string const &path);
  virtual ~Arrow() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual char getLetter() const;
};

#endif
