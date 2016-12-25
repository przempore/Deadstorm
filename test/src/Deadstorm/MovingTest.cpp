#include "gmock/gmock.h"
#include "MovingSprite.hpp"

using namespace testing;

namespace Deadstorm
{
    TEST(Moving_Test, Move_method)
    {
        std::unique_ptr<Actor> actor = std::make_unique<MovingSprite>();
    }
}