#ifndef SHEETSCOLLECTION_H
#define SHEETSCOLLECTION_H

#include "base/mutable.h"
#include "base/collection/collection.h"

namespace Plotypus
{
    struct SheetsCollection:
        public virtual Mutable,
        public virtual Validatable,
        public virtual Collection<Sheet>
    {
        size_t addSheet(const Sheet* newSheet);
        Sheet& getSheet(const size_t idx);

        template<SheetType T>
        T& getSheetAs(const size_t idx)
        {
            return dynamic_cast<T&>(getSheet(idx));
        }
    };
}

#endif // SHEETSCOLLECTION_H
