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
            using Iterator = typename ArrayIterable<T>::Iterator;
            using ConstIterator = typename ArrayConstIterable<T>::ConstIterator;

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

            void forEach(std::function<void (T&)> action);

            // ArrayIterable interface
            Iterator begin();
            Iterator end();

            // ArrayConstIterable interface
            ConstIterator cbegin() const;
            ConstIterator cend() const;

            ConstIterator begin() const;
            ConstIterator end() const;
    };
}

#include "array.txx"

#endif // DEFAULTCOLLECTION_H
