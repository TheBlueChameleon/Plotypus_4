#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>

namespace Plotypus
{
    template<class T>
    class Collection
    {
        private:
            std::vector<T*> data;

        protected:
            const std::vector<T*>& expose() const;

            const size_t size() const;
            T& operator[](size_t idx);

            Collection<T>& add(T* element);
            Collection<T>& clear();
    };
}

#include "collection.txx"

#endif // COLLECTION_H
