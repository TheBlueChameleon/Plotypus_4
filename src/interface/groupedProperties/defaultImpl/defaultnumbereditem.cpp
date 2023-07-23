#include "defaultnumbereditem.h"

namespace Plotypus
{
    size_t DefaultNumberedItem::getNumber() const
    {
        return number;
    }

    void DefaultNumberedItem::setNumber(size_t newNumber)
    {
        number = newNumber;
    }

    void DefaultNumberedItem::reset()
    {
        number = 0;
    }
}
