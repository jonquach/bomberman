#ifndef GROUND_HPP_
#define GROUND_HPP_

#include "AObject.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Ground : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
public:
  Ground() { }
  virtual ~Ground() { }
  virtual bool initialize()
  {
    _speed = 10.0f;

    if (_texture.load("./img/herbe.tga") == false)
      return (false);

    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();

    this->translate(glm::vec3(0, 0, 1) * 1.0f);
    this->translate(glm::vec3(1, 0, 0) * 1.0f);

    return (true);
  }

  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    static_cast<void>(clock);
    static_cast<void>(input);
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

#endif
