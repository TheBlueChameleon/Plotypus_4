#ifndef DEFAULTSHEETSCOLLECTION_H
#define DEFAULTSHEETSCOLLECTION_H

#include "base/collection/array.h"
#include "sheetscollection.h"

namespace Plotypus
{
    class DefaultSheetsCollection :
        public virtual SheetsCollection
    {
        private:
            Array<Sheet> sheets;

        protected:
            // Collection interface
            size_t add(Sheet* element);
            size_t add(const std::shared_ptr<Sheet>& element);

            // SheetsCollection interface
            size_t addSheet(Sheet* newSheet);

        public:
            DefaultSheetsCollection() = default;

            Sheet& getSheet(const size_t idx);
            template<SheetType T>
            T& getSheetAs(size_t idx);

            // NamedType interface
            static std::string getTypeName();
            std::string getInstanceName() const;

            // Collection interface
            size_t size() const;
            bool empty() const;
            bool operator ==(const Plotypus::Collection<Sheet>& other) const;
            void clear();
            void forEachExposed(std::function<void (Sheet*)> action);
            void forEachExposed(std::function<void (const Sheet*)> action) const;

            // Validatable interface
            ValidationResult validate() const;

            // Mutable interface
            void reset();
    };
}

#include "defaultsheetscollection.txx"

#endif // DEFAULTSHEETSCOLLECTION_H
