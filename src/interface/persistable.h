#ifndef PERSISTABLE_H
#define PERSISTABLE_H

#include <filesystem>
#include <optional>

#include "../typesystem/types.h"
#include "../base/validationresult.h"

namespace Plotypus
{
    struct Persistable
    {
        virtual void reset() = 0;

        virtual const std::filesystem::path& getPath() const = 0;
        virtual void setPath(const std::filesystem::path& newFile) = 0;

        virtual bool getMakeDirectories() const = 0;
        virtual void setMakeDirectories(bool newMakePaths) = 0;

        virtual bool getOverwrite() const = 0;
        virtual void setOverwrite(bool newOverwrite) = 0;

        virtual std::ofstream getFileStream() const = 0;
        virtual std::ostringstream getStringStream() = 0;

        virtual ValidationResult validate() const = 0;
    };
}

#endif // PERSISTABLE_H
