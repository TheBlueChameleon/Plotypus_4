#ifndef POLYMORPHICLIST_H
#define POLYMORPHICLIST_H

#include <vector>

namespace Plotypus
{
    template<typename T>
    class PolymorphicList : public Collection<T>
    {
        private:
            std::vector<T*> elements;

        public:
            PolymorphicList() = default;
            ~PolymorphicList();

            // Collection interface
            size_t size() const;
            bool empty() const;

            bool operator =(const Collection<T>& other);
            bool operator =(const PolymorphicList<T>& other);

            size_t add(T* element);
            void clear();

            void forEach(std::function<void (T&)> action);
    };
}

#include "polymorphiclist.txx"

#endif // POLYMORPHICLIST_H
