#ifndef		BONUS_HPP_
# define	BONUS_HPP_

#include "Geometry.hh"
#include "AObject.hpp"

class Bonus : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  std::string _path;

public:
  Bonus(eState);
  virtual ~Bonus() { }

public:
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual char getLetter() const;
};

#endif
