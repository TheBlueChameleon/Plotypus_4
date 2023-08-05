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
            std::vector<T*> elements;

        public:
            Array() = default;
            ~Array();

            std::vector<T*>&       expose();
            const std::vector<T*>& expose() const;

            // Collection interface
            size_t size() const;
            bool empty() const;

            bool operator ==(const Collection<T>& other);
            bool operator ==(const Array<T>& other);

            size_t add(T* element);
            void clear();

            void forEachExposed(std::function<void (T*)> action);

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
