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

    std::ostringstream DefaultPropagatingPersistable::getStringStream()
    {
        return DefaultPersistable::getStringStream();
    }
}
