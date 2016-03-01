#ifndef GEM_SYSTEM_HPP
#define GEM_SYSTEM_HPP

namespace Gem
{
    class System
    {
    public:
        static void Abort();
        static void ReportFailure(const char* message,
                                  const char* expression,
                                  const char* file,
                                  int line);
    };
}

#endif
