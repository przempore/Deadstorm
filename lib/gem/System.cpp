#include "gem/System.hpp"

#include <cstdio>
#include <cstdlib>

namespace Gem
{
    void System::Abort()
    {
        std::abort();
    }

    void System::ReportFailure(const char* message,
                               const char* expression,
                               const char* file,
                               int line)
    {
        printf("%s with expression \"%s\" in file \"%s\" at line %i",
               message,
               expression,
               file,
               line);
    }
}
