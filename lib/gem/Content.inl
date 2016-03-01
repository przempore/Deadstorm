namespace Gem
{
    template<class T_>
    inline std::shared_ptr<T_> Content::Acquire(const std::string& path,
                                                bool cache)
    {
        return std::dynamic_pointer_cast<T_>(Acquire(path, cache));
    }
}
