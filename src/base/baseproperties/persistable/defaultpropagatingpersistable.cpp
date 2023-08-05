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

    void DefaultPropagatingPersistable::addSubscriber(Persistable& subscriber)
    {
        //subscribers.add(&subscriber);
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
}
