#include "arrayiterable.h"

namespace Plotypus
{
    template<typename T>
    ArrayIterable<T>::Iterator::Iterator(pointer ptr) : mPtr(ptr)
    {}

    template<typename T>
    ArrayIterable<T>::Iterator::Iterator(): mPtr(nullptr)
    {}

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator++()
    {
        ++mPtr;
        return *this;
    }


    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

// member
    template<typename T>
    typename ArrayIterable<T>::Iterator::reference ArrayIterable<T>::Iterator::operator*()
    {
        return **mPtr;
    }

// friend
    template<typename T>
    typename ArrayIterable<T>::Iterator::reference operator*(const typename ArrayIterable<T>::Iterator& it)
    {
        return *(it.mPtr);
    }

    template<typename T>
    bool ArrayIterable<T>::Iterator::operator==(const Iterator& it) const
    {
        return mPtr == it.mPtr;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator--()
    {
        --mPtr;
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
    std::weak_ordering ArrayIterable<T>::Iterator::operator<=>(const Iterator& it) const
    {
        return mPtr <=> it.mPtr;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator::difference_type ArrayIterable<T>::Iterator::operator-(const Iterator& it) const
    {
        return mPtr - it.mPtr;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator+=(difference_type diff)
    {
        mPtr += diff;
        return *this;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator& ArrayIterable<T>::Iterator::operator-=(difference_type diff)
    {
        mPtr -= diff;
        return *this;
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator+(difference_type diff) const
    {
        return Iterator(mPtr + diff);
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator ArrayIterable<T>::Iterator::operator-(difference_type diff) const
    {
        return Iterator(mPtr - diff);
    }


    template<typename T>
    typename ArrayIterable<T>::Iterator::reference ArrayIterable<T>::Iterator::operator[](difference_type diff) const
    {
        return *mPtr[diff];
    }

    template<typename T>
    typename ArrayIterable<T>::Iterator::pointer ArrayIterable<T>::Iterator::operator->() const
    {
        return *mPtr;
    }
}
