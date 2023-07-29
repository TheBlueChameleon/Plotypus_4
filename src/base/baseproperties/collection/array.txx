#include "array.h"
#include "typesystem/errors.h"

namespace Plotypus
{
    template<typename T>
    Array<T>::~Array()
    {
        clear();
    }

    template<typename T>
    size_t Array<T>::size() const
    {
        return elements.size();
    }

    template<typename T>
    std::vector<T*>& Array<T>::expose()
    {
        return elements;
    }

    template<typename T>
    const std::vector<T*>& Array<T>::expose() const
    {
        return elements;
    }

    template<typename T>
    bool Array<T>::empty() const
    {
        return elements.empty();
    }

    template<typename T>
    bool Array<T>::operator ==(const Collection<T>& other)
    {
        return false;
    }

    template<typename T>
    bool Array<T>::operator ==(const Array<T>& other)
    {
        if (!std::is_same<decltype(*this), decltype(other)>::value)
        {
            return false;
        }

        const std::vector<T*>& otherElements = other.elements;
        return elements == otherElements;
    }

    template<typename T>
    size_t Array<T>::add(T* element)
    {
        elements.push_back(element);
        return elements.size();
    }

    template<typename T>
    void Array<T>::clear()
    {
        for (T* x : elements)
        {
            delete x;
        }
        elements.clear();
    }

    template<typename T>
    void Array<T>::forEach(std::function<void (T&)> action)
    {
        if (action)
        {
            for (T* x : elements)
            {
                action(*x);
            }
        }
        else
        {
            throw InvalidArgumentError("No valid callable provided");
        }
    }

    template<typename T>
    typename Array<T>::Iterator Array<T>::begin()
    {
        return decltype(begin()) (elements.begin().base());
    }

    template<typename T>
    typename Array<T>::Iterator Array<T>::end()
    {
        return decltype(end()) (elements.end().base());
    }

    template<typename T>
    typename Array<T>::ConstIterator Array<T>::cbegin() const
    {
        const T** ptr =const_cast<const typename ConstIterator::pointer>(elements.begin().base());
        return ConstIterator(ptr);
    }

    template<typename T>
    typename Array<T>::ConstIterator Array<T>::cend() const
    {
        const T** ptr =const_cast<const typename ConstIterator::pointer>(elements.end().base());
        return ConstIterator(ptr);
    }

    template<typename T>
    typename Array<T>::ConstIterator Array<T>::begin() const
    {
        return this->cbegin();
    }

    template<typename T>
    typename Array<T>::ConstIterator Array<T>::end() const
    {
        return this->cend();
    }
}
