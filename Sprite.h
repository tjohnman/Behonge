#include "includes.h"

class Sprite {
public:
    /*
        Create a sprite with a given position and texture (loaded via Graphics).
        Frame width should be specified for animating non-square sprite sheets.
    */
    Sprite(const double x, const double y, const std::string graphicsName, const unsigned frameWidth=0);
    Sprite();
    ~Sprite();

    /*
        Register an animation using sub-rectangles from the sprite's texture.
    */
    void addAnimation(const std::string animationName, const unsigned duration=0, const unsigned firstFrame=0, const unsigned frameCount=0);

    /*
        Draw the sprite.
    */
    void draw(sf::RenderTarget * target);

    /*
        Set the sprite to draw and update any previously registered animation.
    */
    void playAnimation(const std::string animationName, const bool forceRestart=false);

    /*
        Update should be called to advance the sprite's animation (if any).
    */
    void update(double delta);

    /*
        Getter and setter for the sprite's position.
    */
    void setPosition(double x, double y);
    sf::Vector2f getPosition();
private:
    void _updateTextureRect();
    
    struct _tAnimation {
        double frame; // Current frame.
        unsigned firstFrame; // First frame index of the animation.
        unsigned frameCount; // Number of total frames in animation.
        unsigned duration; // Animation duration in milliseconds.
    };

    _tAnimation * _mCurrentAnimation;
    unsigned _mFrameWidth;
    std::map<std::string, _tAnimation> _mAnimations;
    sf::Sprite _mSprite;
};