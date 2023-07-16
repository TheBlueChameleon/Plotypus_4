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
        virtual const std::filesystem::path& getFile() const = 0;
        virtual void setFile(const std::filesystem::path& newFile) = 0;

        virtual bool getMakePaths() const = 0;
        virtual void setMakePaths(bool newMakePaths) = 0;

        virtual bool getOverwrite() const = 0;
        virtual void setOverwrite(bool newOverwrite) = 0;

        virtual std::ofstream getFileStream() = 0;
        virtual std::ostringstream getStringStream() = 0;

        virtual ValidationResult validateFilename() = 0;
    };
}

#endif // PERSISTABLE_H
