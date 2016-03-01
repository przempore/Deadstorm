#include "gem/Logger.hpp"

#ifdef __linux__
    #include <iostream>
#elif _WIN32
    #include <windows.h>
#else

#endif

namespace Gem
{
    void Logger::Log(const char* message, Level level)
    {
        if (level <= m_threshold)
        {
            #ifdef _WIN32
                OutputDebugStringA(message);
            #elif __linux__
                std::cerr << message << std::endl;
            #endif
        }
    }

    void Logger::Log(const std::string& message, Level level)
    {
        if (level <= m_threshold)
        {
            #ifdef _WIN32
                OutputDebugStringA(message.c_str());
            #elif __linux__
                std::cerr << message << std::endl;
            #endif
        }
    }
}
