#include "defaultsheetscollection.h"

namespace Plotypus
{
    size_t DefaultSheetsCollection::add(Sheet* element)
    {
        return add(std::shared_ptr<Sheet>(element));
    }

    size_t DefaultSheetsCollection::add(const std::shared_ptr<Sheet>& element)
    {
        sheets.expose().push_back(element);
        return sheets.size();
    }

    size_t DefaultSheetsCollection::addSheet(Sheet* newSheet)
    {
        return add(newSheet);
    }

    Sheet& DefaultSheetsCollection::getSheet(const size_t idx)
    {
        return sheets.getRef(idx);
    }

    std::string DefaultSheetsCollection::getTypeName()
    {
        return "DefaultSheetsCollection";
    }

    std::string DefaultSheetsCollection::getInstanceName() const
    {
        return getTypeName();
    }

    size_t DefaultSheetsCollection::size() const
    {
        return sheets.size();
    }

    bool DefaultSheetsCollection::empty() const
    {
        return sheets.empty();
    }

    bool DefaultSheetsCollection::operator ==(const Plotypus::Collection<Sheet>& other) const
    {
        // TODO: fully implement
        return false;
    }

    void DefaultSheetsCollection::clear()
    {
        sheets.clear();
    }

    void DefaultSheetsCollection::forEachExposed(std::function<void (Sheet*)> action)
    {
        sheets.forEachExposed(action);
    }

    void DefaultSheetsCollection::forEachExposed(std::function<void (const Sheet*)> action) const
    {
        sheets.forEachExposed(action);
    }

    ValidationResult DefaultSheetsCollection::validate() const
    {
        ValidationResult result;

        for (const auto& sheet : sheets)
        {
            result.absorbValidationResult(sheet.validate(), getInstanceName());
        }

        return result;
    }

    void DefaultSheetsCollection::reset()
    {
        sheets.clear();
    }
}
