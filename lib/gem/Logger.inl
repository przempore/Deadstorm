namespace Gem
{
    inline Logger::Logger()
        : m_threshold(Level::Info)
    {
    }

    inline Logger::Level Logger::Threshold() const
    {
        return m_threshold;
    }

    inline void Logger::SetThreshold(Level threshold)
    {
        m_threshold = threshold;
    }
}
