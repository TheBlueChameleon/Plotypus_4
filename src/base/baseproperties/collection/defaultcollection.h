#ifndef DEFAULTCOLLECTION_H
#define DEFAULTCOLLECTION_H

#include <vector>

namespace Plotypus
{
    template<typename T>
    class DefaultCollection:
        public Collection<T>
    {
        private:
            std::vector<T*> elements;

        public:
            DefaultCollection() = default;
            ~DefaultCollection();

            // Collection interface
            size_t size() const;
            bool empty() const;

            bool operator ==(const Collection<T>& other);
            bool operator ==(const DefaultCollection<T>& other);

            size_t add(T* element);
            void clear();

            void forEach(std::function<void (T&)> action);

            // iterator interface
            using value_type = typename decltype(elements)::value_type;
            using iterator = typename decltype(elements)::iterator;
            using const_iterator = typename decltype(elements)::const_iterator;

            iterator begin();
            const_iterator cbegin() const;

            iterator end();
            const_iterator cend() const;
    };
}

#include "defaultcollection.txx"

#endif // DEFAULTCOLLECTION_H
