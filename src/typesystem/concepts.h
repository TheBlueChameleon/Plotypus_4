#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>

namespace Plotypus
{
    template<typename T>
    concept ErrorType = requires {std::derived_from<T, PlotypusError>;};

    class TerminalInfoProvider;
    template<typename T>
    concept TerminalInfoProviderType = requires {std::derived_from<T, TerminalInfoProvider>;};

    template<typename T>
    concept Iterable = requires(T x)
    {
        x.begin();
        x.end();
        typename T::iterator_category;
    };
}

#endif // CONCEPTS_H
