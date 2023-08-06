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

    // ====================================================================== //

    DefaultPersistable_SP::DefaultPersistable_SP():
        m(std::make_shared<DefaultPersistable>())
    {}

    std::shared_ptr<DefaultPersistable>& DefaultPersistable_SP::get()
    {
        return m;
    }

    std::string DefaultPersistable_SP::getInstanceName() const
    {
        return m->getInstanceName();
    }

    std::string DefaultPersistable_SP::getTypeName()
    {
        return "DefaultPersistable_SP";
    }

    void DefaultPersistable_SP::reset()
    {
        m->reset();
    }

    const std::filesystem::path& DefaultPersistable_SP::getPath() const
    {
        return m->getPath();
    }

    void DefaultPersistable_SP::setPath(const std::filesystem::path& newPath)
    {
        m->setPath(newPath);
    }

    bool DefaultPersistable_SP::getMakeDirectories() const
    {
        return m->getMakeDirectories();
    }

    void DefaultPersistable_SP::setMakeDirectories(bool newMakeDirectories)
    {
        m->setMakeDirectories(newMakeDirectories);
    }

    bool DefaultPersistable_SP::getOverwrite() const
    {
        return m->getOverwrite();
    }

    void DefaultPersistable_SP::setOverwrite(bool newOverwrite)
    {
        m->setOverwrite(newOverwrite);
    }

    bool DefaultPersistable_SP::getAllowNullPath() const
    {
        return m->getAllowNullPath();
    }

    void DefaultPersistable_SP::setAllowNullPath(bool newAllowNullPath)
    {
        m->setAllowNullPath(newAllowNullPath);
    }

    std::ofstream DefaultPersistable_SP::getFileStream() const
    {
        return m->getFileStream();
    }

    std::ostringstream DefaultPersistable_SP::getStringStream() const
    {
        return m->getStringStream();
    }

    bool DefaultPersistable_SP::operator ==(const Persistable& other) const
    {
        return *m == other;
    }

    ValidationResult DefaultPersistable_SP::validate() const
    {
        return m->validate();
    }
}
