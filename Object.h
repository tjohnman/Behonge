#include "includes.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    Object(int x, int y);
    virtual ~Object();

    virtual bool onEvent(const sf::Event & event);
    virtual void draw(sf::RenderTarget * target);
    virtual void update(float delta);

    virtual std::vector<Object *> * getChildren();
    virtual Object * add(Object * object);
    virtual Object * remove(Object * object);

private:
	std::vector<Object *> _m_Children;
};

#endif // OBJECT_H
