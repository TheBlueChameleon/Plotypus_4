#ifndef COLLECTION_H
#define COLLECTION_H

#include <cstddef>
#include <concepts>
#include <functional>
#include <iterator>
#include <memory>

namespace Plotypus
{
    template<typename T>
    struct Collection
    {
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;
        virtual bool operator==(const Collection<T>& other) const = 0;

        virtual size_t add(T* element) = 0;
        virtual size_t add(const std::shared_ptr<T>& element) = 0;
        // virtual void replace(const T& old, const T& replacement) = 0;
        virtual void clear() = 0;

        virtual void forEachExposed(std::function<void(T*)> action) = 0;
        virtual void forEachExposed(std::function<void(const T*)> action) const = 0;
    };

    template<typename T, typename U>
    requires std::equality_comparable_with<T, U>
    void findAndReplace(Collection<T>& collection, const U& old, const U& replacement);
}

#include "collection.txx"

#endif // COLLECTION_H
