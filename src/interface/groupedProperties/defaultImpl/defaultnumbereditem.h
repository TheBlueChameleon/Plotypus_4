#ifndef DEFAULTNUMBEREDITEM_H
#define DEFAULTNUMBEREDITEM_H

#include "../numbereditem.h"

namespace Plotypus
{
    class DefaultNumberedItem : public NumberedItem
    {
        private:
            size_t number;

        public:
            DefaultNumberedItem() = default;

            // NumberedItem interface
            size_t getNumber() const;
            void setNumber(size_t newNumber);

            // Mutable interface
            void reset();
    };
}

#endif // DEFAULTNUMBEREDITEM_H
