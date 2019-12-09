#include "includes.h"

class Sprite {
public:
    Sprite(const double x, const double y, const std::string graphicsName);
    ~Sprite();

    void addAnimation(const std::string animationName, const std::string graphicsName, const unsigned duration=0, const unsigned firstFrame=0, const unsigned frameCount=0);

    void draw(sf::RenderTarget * target);
    void playAnimation(const std::string animationName, const bool forceRestart=false);
    void update(double delta);

    double mX, mY;
private:
    struct _tAnimation {
        std::string graphics; // Name of the texture as loaded via Graphics.
        double frame; // Current frame.
        unsigned firstFrame; // First frame index of the animation.
        unsigned frameCount; // Number of total frames in animation.
        unsigned duration; // Animation duration in milliseconds.
    };

    _tAnimation * _mCurrentAnimation;
    std::map<std::string, _tAnimation> _mAnimations;
    sf::Sprite _mSprite;
};