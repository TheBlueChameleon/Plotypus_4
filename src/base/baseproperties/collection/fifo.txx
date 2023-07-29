#include "fifo.h"


namespace Plotypus
{
    template<typename T>
    FiFo<T>::~FiFo()
    {
        clear();
    }

    template<typename T>
    size_t FiFo<T>::addBack(T* element)
    {
        elements.push_back(element);
    }

    template<typename T>
    size_t FiFo<T>::addFront(T* element)
    {
        elements.push_front(element);
    }

    template<typename T>
    size_t FiFo<T>::size() const
    {
        return elements.size();
    }

    template<typename T>
    bool FiFo<T>::empty() const
    {
        return elements.empty();
    }

    template<typename T>
    bool FiFo<T>::operator ==(const Collection<T>& other)
    {
        return false;
    }

    template<typename T>
    bool FiFo<T>::operator ==(const FiFo<T>& other)
    {
        if (!std::is_same<decltype(*this), decltype(other)>::value)
        {
            return false;
        }

        const std::list<T*>& otherElements = other.elements;
        return elements == otherElements;
    }

    template<typename T>
    size_t FiFo<T>::add(T* element)
    {
        addBack(element);
    }

    template<typename T>
    void FiFo<T>::clear()
    {
        for (auto element : elements)
        {
            delete element;
        }
        elements.clear();
    }

    template<typename T>
    void FiFo<T>::forEach(std::function<void (T&)> action)
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
    typename FiFo<T>::Iterator FiFo<T>::begin()
    {
        return Iterator(elements.begin());
    }

    template<typename T>
    typename FiFo<T>::Iterator FiFo<T>::end()
    {
        return Iterator(elements.end());
    }

    template<typename T>
    typename FiFo<T>::ConstIterator FiFo<T>::begin() const
    {
        return cbegin();
    }

    template<typename T>
    typename FiFo<T>::ConstIterator FiFo<T>::end() const
    {
        return cend();
    }

    template<typename T>
    typename FiFo<T>::ConstIterator FiFo<T>::cbegin() const
    {
        return ConstIterator(elements.cbegin());
    }

    template<typename T>
    typename FiFo<T>::ConstIterator FiFo<T>::cend() const
    {
        return ConstIterator(elements.cend());
    }
}
