#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>
#include <string>

namespace Plotypus
{
    template<typename T>
    concept ErrorType = requires {std::derived_from<T, PlotypusError>;};

    template<typename T>
    concept StaticallyNamedType = requires(T)
    {
        {T::getTypeName()} -> std::convertible_to<std::string>;
    };

    class TerminalInfoProvider;
    template<typename T>
    concept TerminalInfoProviderType = requires {
        requires std::derived_from<T, TerminalInfoProvider>;
        requires StaticallyNamedType<T>;
    };

    template<typename T>
    concept Iterable = requires(T x)
    {
        x.begin();
        x.end();
        typename T::iterator_category;
    };
}

#endif // CONCEPTS_H
