#ifndef COLLECTION_H
#define COLLECTION_H

#include <cstddef>
#include <functional>
#include <iterator>

namespace Plotypus
{
    template<typename T>
    struct Collection
    {
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;

        virtual bool operator==(const Collection<T>& other) = 0;

        virtual size_t add(T* element) = 0;

        virtual void clear() = 0;

        virtual void forEach(std::function<void(T&)> action) = 0;
    };
}

#endif // COLLECTION_H
