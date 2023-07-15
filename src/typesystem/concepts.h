#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>

template<typename Derived, typename Base>
concept Derivative = requires {std::derived_from<Derived, Base>;};

template<typename T>
concept Iterable = requires(T x)
{
    x.begin();
    x.end();
    typename T::iterator_category;
};
#endif // CONCEPTS_H
