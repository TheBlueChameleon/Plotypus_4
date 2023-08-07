#include <fstream>
#include <string>
using namespace std::string_literals;

#include "defaultpersistable.h"

namespace Plotypus
{

    std::string DefaultPersistable::getInstanceName() const
    {
        return getTypeName();
    }

    std::string DefaultPersistable::getTypeName()
    {
        return "DefaultPersistable";
    }

    void DefaultPersistable::reset()
    {
        DefaultPersistableFragment::reset();
    }

    const std::filesystem::path& DefaultPersistable::getPath() const
    {
        return DefaultPersistableFragment::getPath();
    }

    void DefaultPersistable::setPath(const std::filesystem::path& newPath)
    {
        DefaultPersistableFragment::setPath(newPath);
    }

    bool DefaultPersistable::getMakeDirectories() const
    {
        return DefaultPersistableFragment::getMakeDirectories();
    }

    void DefaultPersistable::setMakeDirectories(bool newMakeDirectories)
    {
        DefaultPersistableFragment::setMakeDirectories(newMakeDirectories);
    }

    bool DefaultPersistable::getOverwrite() const
    {
        return DefaultPersistableFragment::getOverwrite();
    }

    void DefaultPersistable::setOverwrite(bool newOverwrite)
    {
        DefaultPersistableFragment::setOverwrite(newOverwrite);
    }

    bool DefaultPersistable::getAllowNullPath() const
    {
        return DefaultPersistableFragment::getAllowNullPath();
    }

    void DefaultPersistable::setAllowNullPath(bool newAllowNullPath)
    {
        DefaultPersistableFragment::setAllowNullPath(newAllowNullPath);
    }

    std::ofstream DefaultPersistable::getFileStream() const
    {
        return DefaultPersistableFragment::getFileStream();
    }

    std::ostringstream DefaultPersistable::getStringStream() const
    {
        return DefaultPersistableFragment::getStringStream();
    }

    bool DefaultPersistable::operator ==(const Persistable& other) const
    {
        const DefaultPersistableFragment* thisFragment = static_cast<const DefaultPersistableFragment*>(this);
        return (*thisFragment) == other;
    }

    ValidationResult DefaultPersistable::validate() const
    {
        ValidationResult result;
        result.absorbValidationResult(DefaultPersistableFragment::validate(), getInstanceName());
        return result;
    }
}
