#include "includes.h"

#ifndef OBJECT_H
#define OBJECT_H

class Behavior;

class Object
{
public:
    Object();
    virtual ~Object();

    virtual bool onEvent(const sf::Event & event);
    virtual void draw(sf::RenderTarget * target);
    virtual void update(float delta);

    virtual std::vector<Object *> * getChildren();
    virtual Object * add(Object * object);
    virtual Object * remove(Object * object);

    void attach(Behavior * behavior);
    void detach(std::string behaviorId);

    float getProperty(std::string propertyId);
    std::string getString(std::string stringId);

private:
	std::vector<Object *> _m_Children;
	std::vector<Behavior *> _m_Behaviors;

	std::map<std::string, float> _m_Properties;
	std::map<std::string, std::string> _m_Strings;
};

#endif // OBJECT_H
