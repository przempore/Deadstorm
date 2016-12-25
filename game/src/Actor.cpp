#include "Actor.hpp"

namespace Deadstorm
{
    Actor::Actor(const std::string &path, int row, int col, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, cached), MovingSprite(path, cached)
    {}

    Actor::Actor(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, cached)
    {}

    Actor::Actor(const std::string &path, int row, int col, int dw, int dh, int posX, int posY, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, posX, posY, cached)
    {}

    Actor::Actor(const std::string &path, int row, int col, int dw, int dh, int posX, int posY, int camX, int camY, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, posX, posY, camX, camY, cached)
    {}

    Actor::Actor(const std::string &path, int row, int col, int dw, int dh, Gem::Point pos, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, pos, cached)
    {}

    Actor::Actor(const std::string &path, int row, int col, int dw, int dh, Gem::Point pos, Gem::Point camPos, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, pos, camPos, cached)
    {}

    Actor::~Actor()
    {}
}
