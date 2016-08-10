#include "NPC.hpp"

namespace Deadstorm
{
    NPC::NPC(const std::string &path, int row, int col, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, cached), MovingSprite(path, cached)
    {}

    NPC::NPC(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, cached)
    {}

    NPC::NPC(const std::string &path, int row, int col, int dw, int dh, int posX, int posY, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, posX, posY, cached)
    {}

    NPC::NPC(const std::string &path, int row, int col, int dw, int dh, Gem::Point pos, bool cached)
            : Sprite(path, cached), AnimSprite(path, row, col, dw, dh, cached), MovingSprite(path, pos, cached)
    {}

    NPC::~NPC()
    {}

    void NPC::Move()
    {

    }
}