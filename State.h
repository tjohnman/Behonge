#include "includes.h"

#ifndef STATE_H
#define STATE_H

/*
**
**	This class represents game states, levels, pages
**	or whatever you can make it work as.
**	At its most basic level it's nothing but a collection
**	of objects really.
**
*/

class Object;

class State
{
public:
	/*
		The constructor accepts a pointer with arbitrary data.
	*/
	State(void * data){};
	virtual ~State(){};

	/*
		Called every time the application receives an event.
		Return value is ignored by default. Can be used to inform
		that the vent was captured.
	*/
	virtual bool onEvent(const sf::Event & event)=0;

	/*
		Called every frame.
	*/
	virtual void draw(sf::RenderTarget * renderTarget)=0;

	/*
		Called every frame.
	*/
	virtual void update(double delta)=0;

	/*
		Add objects that will receive events, update and draw calls.
		Returns NULL if the object was already present. A pointer
		to the object otherwise.
	*/
	Object * add(Object * object);

	/*
		Remove an object. Always returns the same
		pointer it was passed to it.

		The object list remains ordered.
	*/
	Object * remove(Object * object);

private:
	std::vector<Object *> _m_Objects;
};

#endif // STATE_H
