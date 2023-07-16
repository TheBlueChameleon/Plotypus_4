#include <fstream>
#include <sstream>
#include <string>
using namespace std::string_literals;

#include "persistableimpl.h"

namespace Plotypus
{
    const std::filesystem::path& PersistableImpl::getFile() const
    {
        return file;
    }

    PersistableImpl& PersistableImpl::setFile(const std::filesystem::path& newFile)
    {
        file = newFile;
        return *this;
    }

    bool PersistableImpl::getMakePaths() const
    {
        return makePaths;
    }

    PersistableImpl& PersistableImpl::setMakePaths(bool newMakePaths)
    {
        makePaths = newMakePaths;
        return *this;
    }

    bool PersistableImpl::getOverwrite() const
    {
        return overwrite;
    }

    PersistableImpl& PersistableImpl::setOverwrite(bool newOverwrite)
    {
        overwrite = newOverwrite;
        return *this;
    }

    std::ofstream PersistableImpl::getFileStream()
    {
        const auto validation = validateFilename();
        if (validation.has_value())
        {
            throw validation.value();
        }
        else
        {
            auto hFile = std::ofstream(file.string(), std::ios_base::out);
            return hFile;
        }
    }

    std::ostringstream PersistableImpl::getStringStream()
    {
        return std::ostringstream();
    }

    const auto failure = makeValidationResult<FileIOError>;
    ValidationResult PersistableImpl::validateFilename()
    {
        if (!overwrite)
        {
            if (!std::filesystem::exists(file))
            {
                return failure("File '"s + file.string() + "' already exists.");
            }
        }

        const auto& parentDir = file.parent_path();
        if (!std::filesystem::is_directory(parentDir))
        {
            return failure("'"s + parentDir.string() + "' is not a directory.");
        }

        if (!makePaths)
        {
            if (!std::filesystem::exists(parentDir))
            {
                return failure("Directory '"s + parentDir.string() + "' does not exist.");
            }
        }

        return VALIDATION_SUCCESS;
    }
}
