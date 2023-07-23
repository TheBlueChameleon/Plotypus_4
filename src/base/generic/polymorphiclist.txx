#include "polymorphiclist.h"

#include "../../typesystem/errors.h"

namespace Plotypus
{
    template<typename T>
    PolymorphicList<T>::~PolymorphicList()
    {
        clear();
    }

    template<typename T>
    size_t PolymorphicList<T>::size() const
    {
        return elements.size();
    }

    template<typename T>
    bool PolymorphicList<T>::empty() const
    {
        return elements.empty();
    }

    template<typename T>
    bool PolymorphicList<T>::operator ==(const Collection<T>& other)
    {
        return false;
    }

    template<typename T>
    bool PolymorphicList<T>::operator ==(const PolymorphicList<T>& other)
    {
        // *INDENT-OFF*
        if (!std::is_same<decltype(*this), decltype(other)>::value) {return false;}

        const std::vector<T*>& otherElements = other.elements;
        if (elements.size() != otherElements.size()) {return false;}

        for (size_t i = 0u; i < elements.size(); ++i)
        {
            if (elements[i] != otherElements[i]) {return false;}
        }
        // *INDENT-ON*

        return true;
    }

    template<typename T>
    size_t PolymorphicList<T>::add(T* element)
    {
        elements.push_back(element);
        return elements.size();
    }

    template<typename T>
    void PolymorphicList<T>::clear()
    {
        for (T* x : elements)
        {
            delete x;
        }
        elements.clear();
    }

    template<typename T>
    void PolymorphicList<T>::forEach(std::function<void (T&)> action)
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
}
