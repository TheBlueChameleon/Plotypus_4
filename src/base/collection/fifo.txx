#include "fifo.h"


namespace Plotypus
{
    template<typename T>
    size_t FiFo<T>::addBack(T* element)
    {
        elements.emplace_back(element);
    }

    template<typename T>
    size_t FiFo<T>::addBack(const std::shared_ptr<T>& element)
    {
        elements.push_back(element);
    }

    template<typename T>
    size_t FiFo<T>::addFront(T* element)
    {
        elements.emplace_front(element);
    }

    template<typename T>
    size_t FiFo<T>::addFront(const std::shared_ptr<T>& element)
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
    bool FiFo<T>::operator ==(const Collection<T>& other) const
    {
        return false;
    }

    template<typename T>
    bool FiFo<T>::operator ==(const FiFo<T>& other) const
    {
        if (!std::is_same<decltype(*this), decltype(other)>::value)
        {
            return false;
        }

        const decltype(other.elements)& otherElements = other.elements;
        return elements == otherElements;
    }

    template<typename T>
    size_t FiFo<T>::add(T* element)
    {
        addBack(element);
    }

    template<typename T>
    size_t FiFo<T>::add(const std::shared_ptr<T>& element)
    {
        addBack(element);
    }

    //    template<typename T>
    //    void FiFo<T>::replace(const T& old, const T& replacement)
    //    {
    //        const auto first = begin();
    //        const auto last = end();
    //        const auto match = std::find(first, last, old);

    //        if (match == last)
    //        {
    //            throw InvalidArgumentError("Object to replace not found");
    //        }
    //        else
    //        {
    //            *match = replacement;
    //        }
    //    }

    template<typename T>
    void FiFo<T>::clear()
    {
        elements.clear();
    }

    template<typename T>
    void FiFo<T>::forEachExposed(std::function<void (T*)> action)
    {
        if (action)
        {
            for (const std::shared_ptr<T>& x : elements)
            {
                action(x.get());
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
            for (const std::shared_ptr<const T>& x : elements)
            {
                action(x.get());
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