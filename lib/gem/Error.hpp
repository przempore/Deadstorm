#ifndef GEM_ERROR_HPP
#define GEM_ERROR_HPP

namespace Gem
{
    class Error
    {
    public:
        inline Error(const char* what);

    public:
        inline const char* What() const;

    private:
        const char* m_what;
    };
}

#include "gem/Error.inl"

#endif
