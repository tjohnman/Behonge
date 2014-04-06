#include "includes.h"

#ifndef STATE_H
#define STATE_H

class Object;

class State
{
public:
	State(void * data){};
	virtual ~State(){};
	virtual bool onEvent(const sf::Event & event)=0;
	virtual void draw(sf::RenderTarget * renderTarget)=0;
	virtual void update(float delta)=0;

	Object * add(Object * object);
	Object * remove(Object * object);

private:
	std::vector<Object *> _m_Objects;
};

#endif // STATE_H
