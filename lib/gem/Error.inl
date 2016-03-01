namespace Gem
{
    inline Error::Error(const char* what)
        : m_what(what)
    {
    }

    inline const char* Error::What() const
    {
        return m_what;
    }
}
