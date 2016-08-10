#ifndef DEADSTORM_NPC_HPP
#define DEADSTORM_NPC_HPP

#include "AnimSprite.hpp"
#include "MovingSprite.hpp"

namespace Deadstorm
{
    class NPC : public AnimSprite, public MovingSprite
    {
    public:
        NPC(const std::string &path, int row, int col, bool cached);
        NPC(const std::string &path, int row, int col, int dw, int dh, bool cached = false);
        NPC(const std::string &path, int row, int col, int dw, int dh, int posX, int posY, bool cached = false);
        NPC(const std::string &path, int row, int col, int dw, int dh, Gem::Point pos, bool cached = false);

        virtual ~NPC();

    public:
        virtual void Move();
    };
}

#endif //DEADSTORM_NPC_HPP
