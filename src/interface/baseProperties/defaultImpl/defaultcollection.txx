#include "defaultcollection.h"
#include "../../../typesystem/errors.h"

namespace Plotypus
{
    template<typename T>
    DefaultCollection<T>::~DefaultCollection()
    {
        clear();
    }

    template<typename T>
    size_t DefaultCollection<T>::size() const
    {
        return elements.size();
    }

    template<typename T>
    bool DefaultCollection<T>::empty() const
    {
        return elements.empty();
    }

    template<typename T>
    bool DefaultCollection<T>::operator ==(const Collection<T>& other)
    {
        return false;
    }

    template<typename T>
    bool DefaultCollection<T>::operator ==(const DefaultCollection<T>& other)
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
    size_t DefaultCollection<T>::add(T* element)
    {
        elements.push_back(element);
        return elements.size();
    }

    template<typename T>
    void DefaultCollection<T>::clear()
    {
        for (T* x : elements)
        {
            delete x;
        }
        elements.clear();
    }

    template<typename T>
    void DefaultCollection<T>::forEach(std::function<void (T&)> action)
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
