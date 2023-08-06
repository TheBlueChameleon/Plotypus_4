#ifndef DEFAULTNUMBEREDITEM_H
#define DEFAULTNUMBEREDITEM_H

#include "numbereditem.h"

namespace Plotypus
{
    class DefaultNumberedItem : public NumberedItem
    {
        public:
            static constexpr size_t NO_NUMBER = -1;

        private:
            size_t number = NO_NUMBER;

        public:
            DefaultNumberedItem() = default;

            // NumberedItem interface
            size_t getNumber() const;
            void setNumber(size_t newNumber);
            std::string getNumberText() const;

            // Mutable interface
            void reset();
    };
}

#endif // DEFAULTNUMBEREDITEM_H
