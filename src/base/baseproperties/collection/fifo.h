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
            using iterator = typename FiFoIterable<T>::Iterator;
            using const_iterator = typename FiFoConstIterable<T>::ConstIterator;

        private:
            std::list<std::shared_ptr<T>> elements;

        public:
            FiFo() = default;

            size_t addBack(T* element);
            size_t addBack(const std::shared_ptr<T>& element);

            size_t addFront(T* element);
            size_t addFront(const std::shared_ptr<T>& element);

            // Collection interface
            size_t size() const;
            bool empty() const;
            bool operator ==(const Collection<T>& other) const;
            bool operator ==(const FiFo<T>& other) const;
            size_t add(T* element);
            size_t add(const std::shared_ptr<T>& element);
            // void replace(const T& old, const T& replacement);
            void clear();
            void forEachExposed(std::function<void (T*)> action);
            void forEachExposed(std::function<void (const T*)> action) const;

            // FiFoIterable interface
            iterator begin();
            iterator end();

            // FiFoConstIterable interface
            const_iterator cbegin() const;
            const_iterator cend() const;

            const_iterator begin() const;
            const_iterator end() const;
    };

    class T;
    static_assert(Iterable<FiFo<T>>);
    class T;
    static_assert(ConstIterable<FiFo<T>>);
}

#include "fifo.txx"

#endif // FIFO_H
