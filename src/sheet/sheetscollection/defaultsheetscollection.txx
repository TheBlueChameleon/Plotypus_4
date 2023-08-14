#ifndef DEFAULTSHEETSCOLLECTION_TXX
#define DEFAULTSHEETSCOLLECTION_TXX

#include "defaultsheetscollection.h"

namespace Plotypus
{
    template<SheetType T>
    T& DefaultSheetsCollection::getSheetAs(size_t idx)
    {
        std::shared_ptr<Sheet> sheet = sheets.getPtr(idx);
        std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(sheet);
        if (t)
        {
            return *t;
        }
        else
        {
            throw InvalidTypeError("Requested Sheet with index " + std::to_string(idx) + " is not a " + T::getTypeName());
        }
    }
}
#endif // DEFAULTSHEETSCOLLECTION_TXX
