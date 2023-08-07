#ifndef STDRANGEUTILS_H
#define STDRANGEUTILS_H

namespace Plotypus
{
    template <std::ranges::range T, typename U>
    requires std::assignable_from<decltype(std::declval(*T())), U>
    void findAndReplace(T& collection, const U& oldValue, const U& newValue);
}

#include "stdrangeutils.txx"

#endif // STDRANGEUTILS_H
