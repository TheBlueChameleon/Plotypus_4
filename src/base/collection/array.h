#ifndef DEFAULTCOLLECTION_H
#define DEFAULTCOLLECTION_H

#include <vector>

#include "arrayiterable.h"
#include "arrayconstiterable.h"

namespace Plotypus
{
    template<typename T>
    class Array:
        public Collection<T>,
        public ArrayIterable<T>,
        public ArrayConstIterable<T>
    {
        public:
            // iterator types
            using iterator = typename ArrayIterable<T>::Iterator;
            using const_iterator = typename ArrayConstIterable<T>::ConstIterator;

        private:
            std::vector<std::shared_ptr<T>> elements;

        public:
            Array() = default;

            std::vector<std::shared_ptr<T>>&       expose();
            const std::vector<std::shared_ptr<T>>& expose() const;

            std::shared_ptr<T> getPtr(const size_t idx);
            T& getRef(const size_t idx);

            // Collection interface
            size_t size() const;
            bool empty() const;

            bool operator ==(const Collection<T>& other) const;
            bool operator ==(const Array<T>& other) const;

            size_t add(T* element);
            size_t add(const std::shared_ptr<T>& element);
            // void replace(const T& old, const T& replacement);
            void clear();

            void forEachExposed(std::function<void (T*)> action);
            void forEachExposed(std::function<void (const T*)> action) const;

            // ArrayIterable interface
            iterator begin();
            iterator end();

            // ArrayConstIterable interface
            const_iterator cbegin() const;
            const_iterator cend() const;

            const_iterator begin() const;
            const_iterator end() const;
    };

    class T;
    static_assert(Iterable<Array<T>>);

    class T;
    static_assert(ConstIterable<Array<T>>);
}

#include "array.txx"

#endif // DEFAULTCOLLECTION_H
