#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>
#include <memory>
#include <string>

namespace Plotypus
{
    template<typename T>
    concept ErrorType = requires {std::derived_from<T, PlotypusError>;};

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
        requires std::derived_from<T, TerminalInfoProvider>;
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

    class Persistable;
    template<typename T>
    concept PersistableSPType = requires(T x)
    {
        requires std::derived_from<T, Persistable>;

        {
            std::static_pointer_cast<Persistable>(x.get())
        }
        -> std::convertible_to<std::shared_ptr<Persistable>>;
    };
}

#endif // CONCEPTS_H
