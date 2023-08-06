#include <fstream>

#include "defaultpropagatingpersistable.h"

namespace Plotypus
{
    bool DefaultPropagatingPersistable::getPropagateUpdateChildFileNames() const
    {
        return propagateUpdateChildFileNames;
    }

    void DefaultPropagatingPersistable::setPropagateUpdateChildFileNames(const bool newPropagateUpdateChildFileNames)
    {
        propagateUpdateChildFileNames = newPropagateUpdateChildFileNames;
    }

    std::filesystem::path DefaultPropagatingPersistable::getDerivedPath(const std::string& extension, std::optional<std::string> infix)
    {
        const std::filesystem::path parentDir = getPath().parent_path();
        const std::filesystem::path stem = getPath().stem();
        std::filesystem::path result = parentDir / stem;

        if (infix.has_value())
        {
            result += infix.value();
        }

        result.replace_extension(extension);
        return result;
    }



    void DefaultPropagatingPersistable::propagate()
    {
        getSubscribers().forEachExposed([](Persistable* ptr)
        {
            if (PropagatingPersistable* xPtr = dynamic_cast<PropagatingPersistable*>(ptr); xPtr)
            {
                xPtr->propagate();
            }
        });
    }

    void DefaultPropagatingPersistable::addSubscriber(std::shared_ptr<Persistable>& subscriber)
    {
        subscribers.add(subscriber);
    }

    Collection<Persistable>& DefaultPropagatingPersistable::getSubscribers()
    {
        return subscribers;
    }

    void DefaultPropagatingPersistable::reset()
    {
        DefaultPersistable::reset();
        propagateUpdateChildFileNames = true;
    }

    const std::filesystem::path& DefaultPropagatingPersistable::getPath() const
    {
        return DefaultPersistable::getPath();
    }

    void DefaultPropagatingPersistable::setPath(const std::filesystem::path& newPath)
    {
        DefaultPersistable::setPath(newPath);
    }

    bool DefaultPropagatingPersistable::getMakeDirectories() const
    {
        return DefaultPersistable::getMakeDirectories();
    }

    void DefaultPropagatingPersistable::setMakeDirectories(bool newMakeDirectories)
    {
        DefaultPersistable::setMakeDirectories(newMakeDirectories);
    }

    bool DefaultPropagatingPersistable::getOverwrite() const
    {
        return DefaultPersistable::getOverwrite();
    }

    void DefaultPropagatingPersistable::setOverwrite(bool newOverwrite)
    {
        DefaultPersistable::setOverwrite(newOverwrite);
    }

    bool DefaultPropagatingPersistable::getAllowNullPath() const
    {
        return DefaultPersistable::getAllowNullPath();
    }

    void DefaultPropagatingPersistable::setAllowNullPath(bool newAllowNullPath)
    {
        DefaultPersistable::setAllowNullPath(newAllowNullPath);
    }

    std::ofstream DefaultPropagatingPersistable::getFileStream() const
    {
        return DefaultPersistable::getFileStream();
    }

    std::ostringstream DefaultPropagatingPersistable::getStringStream() const
    {
        return DefaultPersistable::getStringStream();
    }

    // ====================================================================== //

    DefaultPropagatingPersistable_SP::DefaultPropagatingPersistable_SP():
        m(std::make_shared<DefaultPropagatingPersistable>())
    {}

    std::shared_ptr<DefaultPropagatingPersistable>& DefaultPropagatingPersistable_SP::get()
    {
        return m;
    }

    std::string DefaultPropagatingPersistable_SP::getInstanceName() const
    {
        return m->getInstanceName();
    }

    std::string DefaultPropagatingPersistable_SP::getTypeName()
    {
        return DefaultPropagatingPersistable::getTypeName();
    }

    void DefaultPropagatingPersistable_SP::reset()
    {
        m->reset();
    }

    bool DefaultPropagatingPersistable_SP::getPropagateUpdateChildFileNames() const
    {
        return m->getPropagateUpdateChildFileNames();
    }

    void DefaultPropagatingPersistable_SP::setPropagateUpdateChildFileNames(const bool newSetUpdateChildFileNames)
    {
        m->setPropagateUpdateChildFileNames(newSetUpdateChildFileNames);
    }

    std::filesystem::path DefaultPropagatingPersistable_SP::getDerivedPath(const std::string& extension, std::optional<std::string> infix)
    {
        return m->getDerivedPath(extension, infix);
    }

    void DefaultPropagatingPersistable_SP::propagate()
    {
        m->propagate();
    }

    void DefaultPropagatingPersistable_SP::addSubscriber(std::shared_ptr<Persistable>& subscriber)
    {
        m->addSubscriber(subscriber);
    }

    Collection<Persistable>& DefaultPropagatingPersistable_SP::getSubscribers()
    {
        return m->getSubscribers();
    }

    const std::filesystem::path& DefaultPropagatingPersistable_SP::getPath() const
    {
        return m->getPath();
    }

    void DefaultPropagatingPersistable_SP::setPath(const std::filesystem::path& newPath)
    {
        m->setPath(newPath);
    }

    bool DefaultPropagatingPersistable_SP::getMakeDirectories() const
    {
        return m->getMakeDirectories();
    }

    void DefaultPropagatingPersistable_SP::setMakeDirectories(bool newMakeDirectories)
    {
        m->setMakeDirectories(newMakeDirectories);
    }

    bool DefaultPropagatingPersistable_SP::getOverwrite() const
    {
        return m->getOverwrite();
    }

    void DefaultPropagatingPersistable_SP::setOverwrite(bool newOverwrite)
    {
        m->setOverwrite(newOverwrite);
    }

    bool DefaultPropagatingPersistable_SP::getAllowNullPath() const
    {
        return m->getAllowNullPath();
    }

    void DefaultPropagatingPersistable_SP::setAllowNullPath(bool newAllowNullPath)
    {
        m->setAllowNullPath(newAllowNullPath);
    }

    std::ofstream DefaultPropagatingPersistable_SP::getFileStream() const
    {
        return m->getFileStream();
    }

    std::ostringstream DefaultPropagatingPersistable_SP::getStringStream() const
    {
        return m->getStringStream();
    }

    ValidationResult DefaultPropagatingPersistable_SP::validate() const
    {
        return m->validate();
    }

}
