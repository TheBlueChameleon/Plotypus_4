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

    std::string DefaultNumberedItem::getNumberText() const
    {
        if (number != NO_NUMBER)
        {
            return "# " + std::to_string(number);
        }
        else
        {
            return "";
        }
    }

    void DefaultNumberedItem::reset()
    {
        number = 0;
    }
}
