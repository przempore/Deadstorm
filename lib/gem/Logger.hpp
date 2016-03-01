#ifndef GEM_LOGGER_HPP
#define GEM_LOGGER_HPP

#include "gem/Singleton.hpp"

#include <string>

namespace Gem
{
    class Logger : public Singleton<Logger>
    {
    public:
        enum class Level
        {
            None,
            Fatal,
            Error,
            Warning,
            Info,
            Debug,
            All
        };

    public:
        inline Logger();

    public:
        inline Level Threshold() const;
        inline void SetThreshold(Level threshold);

    public:
        void Log(const char* message,
                 Level level=Level::Info);
        void Log(const std::string& message,
                 Level level=Level::Info);

    private:
        Level m_threshold;
    };
}

#define g_logger Logger::Instance()

#include "gem/Logger.inl"

#endif
