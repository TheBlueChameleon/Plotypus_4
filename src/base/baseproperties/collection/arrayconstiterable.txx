#include "arrayconstiterable.h"

namespace Plotypus
{
    template<typename T>
    ArrayConstIterable<T>::ConstIterator::ConstIterator(pointer ptr) : mPtr(ptr)
    {}

    template<typename T>
    ArrayConstIterable<T>::ConstIterator::ConstIterator(): mPtr(nullptr)
    {}


    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator++()
    {
        ++mPtr;
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
        return **mPtr;
    }

// friend
    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::reference operator*(const typename ArrayConstIterable<T>::ConstIterator& it)
    {
        return *(it.mPtr);
    }

    template<typename T>
    bool ArrayConstIterable<T>::ConstIterator::operator==(const ConstIterator& it) const
    {
        return mPtr == it.mPtr;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator--()
    {
        --mPtr;
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
    std::weak_ordering ArrayConstIterable<T>::ConstIterator::operator<=>(const ConstIterator& it) const
    {
        return mPtr <=> it.mPtr;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::difference_type ArrayConstIterable<T>::ConstIterator::operator-(const ConstIterator& it) const
    {
        return mPtr - it.mPtr;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator+=(difference_type diff)
    {
        mPtr += diff;
        return *this;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator& ArrayConstIterable<T>::ConstIterator::operator-=(difference_type diff)
    {
        mPtr -= diff;
        return *this;
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator ArrayConstIterable<T>::ConstIterator::operator+(difference_type diff) const
    {
        return ConstIterator(mPtr + diff);
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator ArrayConstIterable<T>::ConstIterator::operator-(difference_type diff) const
    {
        return ConstIterator(mPtr - diff);
    }


    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::reference ArrayConstIterable<T>::ConstIterator::operator[](difference_type diff) const
    {
        return *mPtr[diff];
    }

    template<typename T>
    typename ArrayConstIterable<T>::ConstIterator::pointer ArrayConstIterable<T>::ConstIterator::operator->() const
    {
        return *mPtr;
    }
}
