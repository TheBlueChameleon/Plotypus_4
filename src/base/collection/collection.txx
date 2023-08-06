namespace Plotypus
{
    template<typename T, typename U>
    void findAndReplace(Collection<T>& collection, const U& old, const U& replacement)
    {
        const auto first = collection.begin();
        const auto last = collection.end();
        const auto match = std::find(first, last, old);

        if (match == last)
        {
            throw InvalidArgumentError("Object to replace not found");
        }
        else
        {
            *match = replacement;
        }
    }
}
