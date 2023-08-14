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
        protected:
            virtual size_t addSheet(Sheet* newSheet) = 0;
            virtual Sheet& getSheet(const size_t idx) = 0;

        public:
            template<SheetType T, class ... Args>
            T& emplace(Args ... args)
            {
                T* newSheet = new T(args...);
                addSheet(newSheet);
                return *newSheet;
            }

            template<SheetType T>
            T& getSheetAs(const size_t idx)
            {
                return dynamic_cast<T&>(getSheet(idx));
            }
    };
}

#endif // SHEETSCOLLECTION_H
