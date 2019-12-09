#include "includes.h"
#include "Object.h"
#include "Sprite.h"

#ifndef OBJECTTEST_H
#define OBJECTTEST_H

class ObjectTest : public Object {
public:
    ObjectTest();
    void draw(sf::RenderTarget * target);
    void update(double delta);

private:
    Sprite testSprite;
};

#endif