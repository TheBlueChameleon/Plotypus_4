#ifndef PERSISTABLE_H
#define PERSISTABLE_H

#include <filesystem>
#include <optional>

#include "../../typesystem/types.h"

namespace Plotypus
{
    struct Persistable
    {
        virtual const std::filesystem::path& getPath() const = 0;
        virtual void setPath(const std::filesystem::path& newPath) = 0;

        virtual bool getMakeDirectories() const = 0;
        virtual void setMakeDirectories(bool newMakeDirectories) = 0;

        virtual bool getOverwrite() const = 0;
        virtual void setOverwrite(bool newOverwrite) = 0;

        virtual bool getAllowNullPath() const = 0;
        virtual void setAllowNullPath(bool newAllowNullPath) = 0;

        virtual std::ofstream getFileStream() const = 0;
        virtual std::ostringstream getStringStream() = 0;
    };
}

#endif // PERSISTABLE_H
