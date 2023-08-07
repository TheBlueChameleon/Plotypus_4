#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>
#include <memory>
#include <string>

namespace Plotypus
{
    template<typename T>
    concept ErrorType = requires {std::is_base_of<PlotypusError, T>::value;};

    template<typename T>
    concept StaticallyNamedType = requires(T)
    {
        {
            T::getTypeName()
        }
        -> std::convertible_to<std::string>;
    };

    class TerminalInfoProvider;
    template<typename T>
    concept TerminalInfoProviderType = requires
    {
        requires std::is_base_of<TerminalInfoProvider, T>::value;
        requires StaticallyNamedType<T>;
    };

    template<typename T>
    concept Iterable = requires(T x)
    {
        x.begin();
        x.end();
        typename T::iterator;
    };

    template<typename T>
    concept ConstIterable = requires(T x)
    {
        x.cbegin();
        x.cend();
        typename T::const_iterator;
    }
    && requires(T const x)
    {
        x.begin();
        x.end();
    };
}

#endif // CONCEPTS_H
