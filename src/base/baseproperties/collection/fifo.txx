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
    void FiFo<T>::forEachExposed(std::function<void (T*)> action)
    {
        if (action)
        {
            for (T* x : elements)
            {
                action(x);
            }
        }
        else
        {
            throw InvalidArgumentError("No valid callable provided");
        }
    }

    template<typename T>
    void FiFo<T>::forEachExposed(std::function<void (const T*)> action) const
    {
        if (action)
        {
            for (const T* x : elements)
            {
                action(x);
            }
        }
        else
        {
            throw InvalidArgumentError("No valid callable provided");
        }
    }

    template<typename T>
    typename FiFo<T>::iterator FiFo<T>::begin()
    {
        return iterator(elements.begin());
    }

    template<typename T>
    typename FiFo<T>::iterator FiFo<T>::end()
    {
        return iterator(elements.end());
    }

    template<typename T>
    typename FiFo<T>::const_iterator FiFo<T>::begin() const
    {
        return cbegin();
    }

    template<typename T>
    typename FiFo<T>::const_iterator FiFo<T>::end() const
    {
        return cend();
    }

    template<typename T>
    typename FiFo<T>::const_iterator FiFo<T>::cbegin() const
    {
        return const_iterator(elements.cbegin());
    }

    template<typename T>
    typename FiFo<T>::const_iterator FiFo<T>::cend() const
    {
        return const_iterator(elements.cend());
    }
}
