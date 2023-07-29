#ifndef FIFO_H
#define FIFO_H

#include <list>

#include "base/baseproperties/collection.h"
#include "base/baseproperties/collection/fifoiterable.h"
#include "fifoconstiterable.h"

namespace Plotypus
{
    template <typename T>
    class FiFo:
        public Collection<T>,
        public FiFoIterable<T>,
        public FiFoConstIterable<T>
    {
        public:
            // iterator types
            using Iterator = typename FiFoIterable<T>::Iterator;
            using ConstIterator = typename FiFoConstIterable<T>::ConstIterator;

        private:
            std::list<T*> elements;

        public:
            FiFo() = default;
            ~FiFo();

            size_t addBack(T* element);
            size_t addFront(T* element);

            // Collection interface
            size_t size() const;
            bool empty() const;
            bool operator ==(const Collection<T>& other);
            bool operator ==(const FiFo<T>& other);
            size_t add(T* element);
            void clear();
            void forEach(std::function<void (T&)> action);

            // FiFoIterable interface
            Iterator begin();
            Iterator end();

            // FiFoConstIterable interface
            ConstIterator cbegin() const;
            ConstIterator cend() const;

            ConstIterator begin() const;
            ConstIterator end() const;
    };
}

#include "fifo.txx"

#endif // FIFO_H
