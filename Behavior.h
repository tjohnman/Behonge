#include "includes.h"

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

class Object;

class Behavior
{
public:
    Behavior(std::string id) : _m_Id(id) {};
    virtual ~Behavior(){};

    Object * m_Object;

    virtual bool onEvent(const sf::Event & event)=0;
    virtual void draw(sf::RenderTarget * target)=0;
    virtual void update(float delta)=0;

	std::string getId(){return _m_Id;};

private:
	std::string _m_Id;
};

#endif // BEHAVIOR_H
