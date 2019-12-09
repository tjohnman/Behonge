#include "Sprite.h"
#include "Graphics.h"
#include <cmath>

Sprite::Sprite() {

}

Sprite::Sprite(const double x, const double y, const std::string graphicsName, const unsigned frameWidth) {
    this->_mSprite.setTexture(Graphics::GetTexture(graphicsName));
    this->_mSprite.setPosition(x, y);
    this->_mCurrentAnimation = 0;
    
    if(frameWidth == 0) this->_mFrameWidth = this->_mSprite.getTexture()->getSize().y;
    else this->_mFrameWidth = frameWidth;
}

Sprite::~Sprite() {

}

void Sprite::addAnimation(const std::string animationName, const unsigned duration, const unsigned firstFrame, const unsigned frameCount) {
    this->_mAnimations[animationName] = { static_cast<double>(firstFrame), firstFrame, frameCount, duration };
}

void Sprite::draw(sf::RenderTarget * target) {
    target->draw(this->_mSprite);
}

void Sprite::playAnimation(const std::string animationName, const bool forceRestart) {
    if(animationName == "") {
        this->_mCurrentAnimation = 0;
        this->_mSprite.setTextureRect(sf::IntRect(sf::Vector2<int>(0, 0), sf::Vector2<int>(this->_mSprite.getTexture()->getSize().x, this->_mSprite.getTexture()->getSize().y)));
        return;
    }

    if(forceRestart) {
        this->_mAnimations[animationName].frame = this->_mAnimations[animationName].firstFrame;
    }

    this->_mCurrentAnimation = &(this->_mAnimations[animationName]);
    this->_updateTextureRect();
}

void Sprite::_updateTextureRect() {
    if(this->_mCurrentAnimation) {
        const sf::Texture * texture = this->_mSprite.getTexture();
        const unsigned startOffset = static_cast<unsigned>(floor(this->_mCurrentAnimation->frame)) * this->_mFrameWidth;
        this->_mSprite.setTextureRect(sf::IntRect(sf::Vector2<int>(startOffset, 0), sf::Vector2<int>(this->_mFrameWidth, texture->getSize().y)));
    }
}

void Sprite::update(double delta) {
    if(this->_mCurrentAnimation && this->_mCurrentAnimation->duration) {
        double frameOffset = delta * (1.0/(((double) this->_mCurrentAnimation->duration / (double) this->_mCurrentAnimation->frameCount) / 1000.0));
        this->_mCurrentAnimation->frame += frameOffset;
    }

    if(floor(this->_mCurrentAnimation->frame) >= this->_mCurrentAnimation->frameCount) {
        this->_mCurrentAnimation->frame = this->_mCurrentAnimation->firstFrame;
    } else if (floor(this->_mCurrentAnimation->frame) < this->_mCurrentAnimation->firstFrame) {
        this->_mCurrentAnimation->frame = this->_mCurrentAnimation->firstFrame;
    }

    this->_updateTextureRect();
}

void Sprite::setPosition(double x, double y) {
    this->_mSprite.setPosition(x, y);
}

sf::Vector2f Sprite::getPosition() {
    return this->_mSprite.getPosition();
}