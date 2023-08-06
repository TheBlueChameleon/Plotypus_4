#include "fifoconstiterable.h"

namespace Plotypus
{
    template<typename T>
    FiFoConstIterable<T>::ConstIterator::ConstIterator(const native_iterator_type& iter): iter(iter)
    {}

    template<typename T>
    typename FiFoConstIterable<T>::ConstIterator& FiFoConstIterable<T>::ConstIterator::operator++()
    {
        ++iter;
        return *this;
    }

    template<typename T>
    typename FiFoConstIterable<T>::ConstIterator FiFoConstIterable<T>::ConstIterator::operator++(int)
    {
        auto tmp = iter++;
        return tmp;
    }

    template<typename T>
    typename FiFoConstIterable<T>::ConstIterator::reference FiFoConstIterable<T>::ConstIterator::operator*()
    {
        return **iter;
    }

    template<typename T>
    typename FiFoConstIterable<T>::ConstIterator::reference operator*(const typename FiFoConstIterable<T>::ConstIterator& it)
    {
        return **it;
    }

    template<typename T>
    bool FiFoConstIterable<T>::ConstIterator::operator==(const ConstIterator& it) const
    {
        return iter == it.iter;
    }

    template<typename T>
    typename FiFoConstIterable<T>::ConstIterator& FiFoConstIterable<T>::ConstIterator::operator--()
    {
        --iter;
        return *this;
    }

    template<typename T>
    typename FiFoConstIterable<T>::ConstIterator FiFoConstIterable<T>::ConstIterator::operator--(int)
    {
        auto tmp = iter--;
        return tmp;
    }
}
