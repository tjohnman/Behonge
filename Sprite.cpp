#include "Sprite.h"
#include "Graphics.h"
#include <cmath>

Sprite::Sprite(const double x, const double y, const std::string graphicsName) {
    this->_mSprite.setTexture(Graphics::GetTexture(graphicsName));
    this->_mSprite.setPosition(x, y);
    this->_mCurrentAnimation = 0;
}

Sprite::~Sprite() {

}

void Sprite::addAnimation(const std::string animationName, const std::string graphicsName, const unsigned duration, const unsigned firstFrame, const unsigned frameCount) {
    this->_mAnimations[animationName] = { graphicsName, static_cast<double>(firstFrame), firstFrame, frameCount, duration };
}

void Sprite::draw(sf::RenderTarget * target) {
    target->draw(this->_mSprite);
}

void Sprite::playAnimation(const std::string animationName, const bool forceRestart) {
    if(animationName == "") {
        this->_mCurrentAnimation = 0;
        return;
    }

    this->_mCurrentAnimation = &(this->_mAnimations[animationName]);
    if(forceRestart) this->_mCurrentAnimation->frame = this->_mCurrentAnimation->firstFrame;
}

void Sprite::update(double delta) {
    if(this->_mCurrentAnimation) {
        double frameOffset = delta * (1/((this->_mCurrentAnimation->duration / this->_mCurrentAnimation->frameCount) / 1000));
        this->_mCurrentAnimation->frame += frameOffset;
        if(floor(this->_mCurrentAnimation->frame) >= this->_mCurrentAnimation->frameCount) {
            this->_mCurrentAnimation->frame = this->_mCurrentAnimation->firstFrame;
        }
    } 
}

void Sprite::setPosition(double x, double y) {
    this->_mSprite.setPosition(x, y);
}

sf::Vector2f Sprite::getPosition() {
    return this->_mSprite.getPosition();
}