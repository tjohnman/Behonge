#include "includes.h"

#ifndef OBJECT_H
#define OBJECT_H

/*
**
**	Objects are the base class for everything else.
**	They can be subclassed and given new members (in which case
**	you should _always_ call the superclass method of any
**	virtual method you override), or you can use properties/strings.
**
**	The default implementations passes events to behaviors
**	and children, but does not act on its own.
**
*/

class Behavior;

class Object
{
public:
    Object();
    virtual ~Object();

	/*
		Called every time the application recieves an event.
		Return value is ignored by the main loop by default.
	*/
    virtual bool onEvent(const sf::Event & event);

    /*
		Called on every frame.
    */
    virtual void draw(sf::RenderTarget * target);

    /*
		Called on every frame.
    */
    virtual void update(double delta);

	/*
		Returns a pointer to our vector of children objects.
	*/
    virtual std::vector<Object *> * getChildren();

    /*
		Add a child object. The same instance can be
		added only once. Returns the object if success,
		NULL if object was already a children.
	*/
    virtual Object * add(Object * object);

    /*
		Remove a child object.
	*/
    virtual Object * remove(Object * object);

	/*
		Add a behavior. Returns the behavior if success,
		NULL if behavior is currently attached somewhere else
		or to this object.
	*/
    Behavior * attach(Behavior * behavior);

    /*
		Detaches a behavior from the object.
    */
    Behavior * detach(std::string behaviorId);

	/*
		Getters/setters for properties and strings.
	*/
    double getProperty(std::string propertyId);
    std::string getString(std::string stringId);

    void setProperty(std::string propertyId, double value);
    void setString(std::string stringId, std::string string);

private:
	std::vector<Object *> _m_Children;
	std::vector<Behavior *> _m_Behaviors;

	std::map<std::string, double> _m_Properties;
	std::map<std::string, std::string> _m_Strings;
};

#endif // OBJECT_H
