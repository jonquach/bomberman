#ifndef     AOBJECT_HPP_
#define     AOBJECT_HPP_

// Mathematic includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// gdl includes
#include <Game.hh>
#include <Model.hh>
#include <Clock.hh>
#include <Input.hh>
//#include <AShader.hh>
#include <Texture.hh>

#include <iostream>
#include <deque>

class AObject
{
public:
  enum eState
    {
      UNDEFINED,
      CUBE,
      BOMB,
      EXPLODED,
      PLAYER,
      TODESTROY,
      BOMBUP = 9,
      POWERUP = 10,
      SPEEDUP = 11,
    };

  // Ctors && Dtor
public:
  AObject();
  AObject(int Px, int Py, int Pz, int Rx, int Ry, int Rz);
  virtual ~AObject() {};

  // Virtual methods
public:
  virtual bool initialize();
  virtual void update(gdl::Clock const& clock, gdl::Input& input,
		      std::deque<AObject *> & dynamicObjects);
  virtual void update(gdl::Clock const& clock, gdl::Input& input);
  virtual void update(gdl::Clock const& clock, gdl::Input& input,
		      std::string mode);
  virtual int   getNbValue() const;
  virtual void draw(gdl::AShader& shader, gdl::Clock const& clock) = 0;
  virtual char		getLetter() const = 0;
  // Methods
public:
  void		translate(glm::vec3 const&);
  void		rotate(glm::vec3 const&, float);
  void		scale(glm::vec3 const&);
  glm::mat4	getTransformation();
  float		getPosX() const;
  float		getPosY() const;
  float		getPosZ() const;
  void		setPosX(float);
  void		setPosY(float);
  void		setPosZ(float);
  eState	getState() const;
  void		setState(eState);
  virtual bool getSetting(){return false;};
  virtual void setSetting(bool);
  virtual int getPosition(){return -1;};

  // Attributs
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  eState	_state;
  char		_letter;
  bool  _setting;
};

#endif
