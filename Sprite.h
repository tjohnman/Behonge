#include "includes.h"

class Sprite {
public:
    Sprite(const double x, const double y);
    ~Sprite();

    void draw(sf::RenderTarget * target);
    void setPosition(const double x, const double y);
private:
    struct _tAnimation {
        std::string graphics;
        double frame;
        unsigned totalFrames;
        unsigned duration;
    };

    double _mX, _mY;
    std::map<std::string, _tAnimation> _mAnimations;
};