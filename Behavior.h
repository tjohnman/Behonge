#include "includes.h"

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

/*
**
**	Behaviors are basically event handlers that attach to objects.
**  Access your object through m_Object. Use properties.
**  Use them to add modular functionality to objects.
**
**  Default implementation does nothing.
**
*/

class Object;

class Behavior
{
public:
	/*
		Give your behavior a string id and determine if
		it should be called on update and draw calls.
	*/
    Behavior(std::string id, bool fireOnUpdate = false, bool fireOnDraw = false)
    :
	m_Object(0),
    m_FireOnUpdate(fireOnUpdate),
    m_FireOnDraw(fireOnDraw),
    _m_Id(id) {};
    virtual ~Behavior(){};

    Object * m_Object;
    bool m_FireOnUpdate, m_FireOnDraw;

	/*
		This method gets called every time the object receives an event.
		Unlike objects, behaviors will always receive an event, even if
		another behavior has catched it. The boolean parameter alreadyCatched
		indicated whether this event was already catched.
	*/
    virtual bool onEvent(const sf::Event & event, bool alreadyCatched = false){return false;};

    /*
		If m_FireOnDraw is true, this method gets called on every frame.
	*/
    virtual void draw(sf::RenderTarget * target){};

    /*
		If m_FireOnUpdate is true, this method gets called on every frame.
	*/
    virtual void update(float delta){};

    /*
		This method gets called just after the behavior is attached to an object.
	*/
    virtual void onAttached(){};

    /*
		This method is called just before the behavior is detached from the object.
		This includes just before object deletion, but not necessarily before
		behavior deletion.
	*/
    virtual void onAboutToDetach(){};

	std::string getId(){return _m_Id;};

private:
	std::string _m_Id;
};

#endif // BEHAVIOR_H
