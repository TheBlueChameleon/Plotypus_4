#include "arrayiterable.h"

namespace Plotypus
{
    template<typename T>
    ArrayIterable<T>::Iterator::Iterator(native_iter_type nIter) : nIter(nIter)
    {}

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator++()
    {
        ++nIter;
        return *this;
    }


    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator::reference ArrayIterable<T>::Iterator::operator*()
    {
        return **nIter;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator::reference operator*(const typename ArrayIterable<T>::Iterator& iter)
    {
        return *(iter.nIter);
    }

    template<typename T>
    bool ArrayIterable<T>::Iterator::operator==(const Iterator& iter) const
    {
        return nIter == iter.nIter;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator--()
    {
        --nIter;
        return *this;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator--(int)
    {
        Iterator tmp = *this;
        --(*this);
        return tmp;
    }

    template<typename T>
    std::weak_ordering ArrayIterable<T>::Iterator::operator<=>(const Iterator& iter) const
    {
        return nIter <=> iter.nIter;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator::difference_type ArrayIterable<T>::Iterator::operator-(const Iterator& iter) const
    {
        return nIter - iter.nIter;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator+=(difference_type diff)
    {
        nIter += diff;
        return *this;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator-=(difference_type diff)
    {
        nIter -= diff;
        return *this;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator+(difference_type diff) const
    {
        return Iterator(nIter + diff);
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator-(difference_type diff) const
    {
        return Iterator(nIter - diff);
    }


    template<typename T>
    typename ArrayIterable<T>::Iterator::reference ArrayIterable<T>::Iterator::operator[](difference_type diff) const
    {
        return *nIter[diff];
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator::pointer ArrayIterable<T>::Iterator::operator->() const
    {
        return *nIter;
    }
}
