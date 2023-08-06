#include "arrayconstiterable.h"

namespace Plotypus
{
    template<typename T>
    ArrayConstIterable<T>::ConstIterator::ConstIterator(native_iter_type nIter) : nIter(nIter)
    {}


    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator++()
    {
        ++nIter;
        return *this;
    }


    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator ArrayConstIterable<T>::ConstIterator::operator++(int)
    {
        ConstIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    // member
    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::reference ArrayConstIterable<T>::ConstIterator::operator*()
    {
        return **nIter;
    }

    // friend
    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::reference operator*(const typename ArrayConstIterable<T>::ConstIterator& iter)
    {
        return *(iter.nIter);
    }

    template<typename T>
    bool ArrayConstIterable<T>::ConstIterator::operator==(const ConstIterator& iter) const
    {
        return nIter == iter.nIter;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator--()
    {
        --nIter;
        return *this;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator ArrayConstIterable<T>::ConstIterator::operator--(int)
    {
        ConstIterator tmp = *this;
        --(*this);
        return tmp;
    }

    template<typename T>
    std::weak_ordering ArrayConstIterable<T>::ConstIterator::operator<=>(const ConstIterator& iter) const
    {
        return nIter <=> iter.nIter;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::difference_type ArrayConstIterable<T>::ConstIterator::operator-(const ConstIterator& iter) const
    {
        return nIter - iter.nIter;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator+=(difference_type diff)
    {
        nIter += diff;
        return *this;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator-=(difference_type diff)
    {
        nIter -= diff;
        return *this;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator ArrayConstIterable<T>::ConstIterator::operator+(difference_type diff) const
    {
        return ConstIterator(nIter + diff);
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator ArrayConstIterable<T>::ConstIterator::operator-(difference_type diff) const
    {
        return ConstIterator(nIter - diff);
    }


    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::reference ArrayConstIterable<T>::ConstIterator::operator[](difference_type diff) const
    {
        return *nIter[diff];
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::pointer ArrayConstIterable<T>::ConstIterator::operator->() const
    {
        return *nIter;
    }
}
