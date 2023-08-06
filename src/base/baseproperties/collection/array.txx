#include "array.h"
#include "typesystem/errors.h"

namespace Plotypus
{
    template<typename T>
    size_t Array<T>::size() const
    {
        return elements.size();
    }

    template<typename T>
    std::vector<std::shared_ptr<T> >& Array<T>::expose()
    {
        return elements;
    }

    template<typename T>
    const std::vector<std::shared_ptr<T> >& Array<T>::expose() const
    {
        return elements;
    }

    template<typename T>
    bool Array<T>::empty() const
    {
        return elements.empty();
    }

    template<typename T>
    bool Array<T>::operator ==(const Collection<T>& other) const
    {
        return false;
    }

    template<typename T>
    bool Array<T>::operator ==(const Array<T>& other) const
    {
        if (!std::is_same<decltype(*this), decltype(other)>::value)
        {
            return false;
        }

        const decltype(other.elements)& otherElements = other.elements;
        return elements == otherElements;
    }

    template<typename T>
    size_t Array<T>::add(T* element)
    {
        elements.emplace_back(element);
        return elements.size();
    }

    template<typename T>
    size_t Array<T>::add(const std::shared_ptr<T>& element)
    {
        elements.push_back(element);
        return elements.size();
    }

    //    template<typename T>
    //    void Array<T>::replace(const T& old, const T& replacement)
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
    void Array<T>::clear()
    {
        elements.clear();
    }

    template<typename T>
    void Array<T>::forEachExposed(std::function<void (T*)> action)
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
    void Array<T>::forEachExposed(std::function<void (const T*)> action) const
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
    typename Array<T>::iterator Array<T>::begin()
    {
        return iterator(elements.begin());
    }

    template<typename T>
    typename Array<T>::iterator Array<T>::end()
    {
        return iterator(elements.end());
    }

    template<typename T>
    typename Array<T>::const_iterator Array<T>::cbegin() const
    {
        return const_iterator(elements.cbegin());
    }

    template<typename T>
    typename Array<T>::const_iterator Array<T>::cend() const
    {
        return const_iterator(elements.cend());
    }

    template<typename T>
    typename Array<T>::const_iterator Array<T>::begin() const
    {
        return this->cbegin();
    }

    template<typename T>
    typename Array<T>::const_iterator Array<T>::end() const
    {
        return this->cend();
    }
}
