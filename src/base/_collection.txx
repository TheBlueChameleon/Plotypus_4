#include "collection.h"

#ifndef COLLECTION_TXX
#define COLLECTION_TXX


namespace Plotypus
{
    template<class T>
    const std::vector<T*>& Collection<T>::expose() const
    {
        return data;
    }

    template<class T>
    Collection<T>& Collection<T>::add(T* element)
    {
        data.push_back(element);
    }

    template<class T>
    const size_t Collection<T>::size() const
    {
        return data.size();
    }
}
#endif // COLLECTION_TXX
