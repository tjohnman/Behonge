#include "ObjectTest.h"
#include "Graphics.h"

ObjectTest::ObjectTest() {
    Graphics::Load("test.png", "testTexture");   
    this->testSprite = Sprite(10, 10, "testTexture", 16);
    this->testSprite.addAnimation("running", 250, 0, 3);
    this->testSprite.playAnimation("running");
}

void ObjectTest::draw(sf::RenderTarget * target) {
    this->testSprite.draw(target);
}

void ObjectTest::update(double delta) {
    this->testSprite.update(delta);
}
