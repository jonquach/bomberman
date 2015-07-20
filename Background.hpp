#include <Game.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <Input.hh>

#include "AObject.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Background : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  std::vector<std::string> _path;

public:
  Background(int Px, int Py, int Pz, int Rx, int Ry, int Rz,
	     std::vector<std::string> path)
    : AObject(Px, Py, Pz, Rx, Ry ,Rz)
  {
    _path = path;
  }

  virtual ~Background() { }

  virtual bool initialize()
  {
    _speed = 10.0f;
    if (_texture.load(_path.at(0)) == false)
      return (false);

    _geometry.pushVertex(glm::vec3(20, -20, 20));
    _geometry.pushVertex(glm::vec3(20, 20, 20));
    _geometry.pushVertex(glm::vec3(-20, 20, 20));
    _geometry.pushVertex(glm::vec3(-20, -20, 20));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();
    return (true);
  }

  virtual void update(gdl::Clock const &clock, gdl::Input &input,
		      std::string mode)
  {
    static_cast<void>(clock);
    static_cast<void>(input);
    static_cast<void>(mode);
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
