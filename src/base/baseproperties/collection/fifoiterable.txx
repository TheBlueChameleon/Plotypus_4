#include "fifoiterable.h"

namespace Plotypus
{
    template<typename T>
    FiFoIterable<T>::Iterator::Iterator(const native_iterator_type& iter): iter(iter)
    {}

    template<typename T>
    typename FiFoIterable<T>::Iterator& FiFoIterable<T>::Iterator::operator++()
    {
        ++iter;
        return *this;
    }

    template<typename T>
    typename FiFoIterable<T>::Iterator FiFoIterable<T>::Iterator::operator++(int)
    {
        auto tmp = iter++;
        return tmp;
    }

    template<typename T>
    typename FiFoIterable<T>::Iterator::reference FiFoIterable<T>::Iterator::operator*()
    {
        return **iter;
    }

    template<typename T>
    typename FiFoIterable<T>::Iterator::reference operator*(const typename FiFoIterable<T>::Iterator& it)
    {
        return **it;
    }

    template<typename T>
    bool FiFoIterable<T>::Iterator::operator==(const Iterator& it) const
    {
        return iter == it.iter;
    }

    template<typename T>
    typename FiFoIterable<T>::Iterator& FiFoIterable<T>::Iterator::operator--()
    {
        --iter;
        return *this;
    }

    template<typename T>
    typename FiFoIterable<T>::Iterator FiFoIterable<T>::Iterator::operator--(int)
    {
        auto tmp = iter--;
        return tmp;
    }
}
