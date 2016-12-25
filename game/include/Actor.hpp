#ifndef DEADSTORM_ACTOR_HPP
#define DEADSTORM_ACTOR_HPP

#include "AnimSprite.hpp"
#include "MovingSprite.hpp"

namespace Deadstorm
{
    class Actor : public AnimSprite, public MovingSprite
    {
    public:
        Actor(const std::string &path, int row, int col, bool cached);
        Actor(const std::string &path, int row, int col, int dw, int dh, bool cached = false);
        Actor(const std::string &path, int row, int col, int dw, int dh, int posX, int posY, bool cached = false);
        Actor(const std::string &path, int row, int col, int dw, int dh, int posX, int posY, int camX, int camY, bool cached = false);
        Actor(const std::string &path, int row, int col, int dw, int dh, Gem::Point pos, bool cached = false);
        Actor(const std::string &path, int row, int col, int dw, int dh, Gem::Point pos, Gem::Point camPos, bool cached = false);

        virtual ~Actor();
    };

    typedef std::shared_ptr<Actor> ActorPtr;
}

#endif //DEADSTORM_ACTOR_HPP
