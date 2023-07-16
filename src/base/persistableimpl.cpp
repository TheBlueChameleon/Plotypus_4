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
        validation.trigger();

        const std::string filename = file.string();
        auto hFile = std::ofstream(filename, std::ios_base::out);

        if (!hFile.is_open())
        {
            throw FileIOError("Could not create file: "s + filename);
        }

        return hFile;
    }

    std::ostringstream PersistableImpl::getStringStream()
    {
        return std::ostringstream();
    }

    const auto failure = ValidationResult::makeValidationResult<FileIOError>;
    ValidationResult PersistableImpl::validateFilename()
    {
        if (!overwrite)
        {
            if (std::filesystem::exists(file))
            {
                return failure("File '"s + file.string() + "' already exists.");
            }
        }

        const auto& parentDir = file.parent_path();
        if (parentDir.empty())
        {
            return ValidationResult::SUCCESS;
        }

        if (!makePaths)
        {
            if (!std::filesystem::exists(parentDir))
            {
                return failure("Directory '"s + parentDir.string() + "' does not exist.");
            }
        }
        else
        {
            if (std::filesystem::exists(parentDir) && !std::filesystem::is_directory(parentDir))
            {
                return failure("'"s + parentDir.string() + "' is not a directory.");
            }
        }

        return ValidationResult::SUCCESS;
    }
}
