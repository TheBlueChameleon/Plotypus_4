#include <fstream>
#include <string>
using namespace std::string_literals;

#include "defaultpersistable.h"

namespace Plotypus
{
    const auto failure = ValidationResult::makeValidationResult<FileIOError>;
    ValidationResult DefaultPersistable::validate() const
    {
        if (!allowNullPath)
        {
            if (path.empty())
            {
                return failure("Filename is empty.");
            }
        }

        if (!overwrite)
        {
            if (std::filesystem::exists(path))
            {
                return failure("File '"s + path.string() + "' already exists.");
            }
        }

        const auto& parentDir = path.parent_path();
        if (parentDir.empty()) // implicitly in CWD -- always valid
        {
            return ValidationResult::SUCCESS;
        }

        if (!makeDirectories)
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

    void DefaultPersistable::reset()
    {
        path.clear();

        makeDirectories = true;
        overwrite = false;
        allowNullPath = false;
    }

    const std::filesystem::path& DefaultPersistable::getPath() const
    {
        return path;
    }

    void DefaultPersistable::setPath(const std::filesystem::path& newPath)
    {
        path = newPath;
    }

    bool DefaultPersistable::getMakeDirectories() const
    {
        return makeDirectories;
    }

    void DefaultPersistable::setMakeDirectories(bool newMakeDirectories)
    {
        makeDirectories = newMakeDirectories;
    }

    bool DefaultPersistable::getOverwrite() const
    {
        return overwrite;
    }

    void DefaultPersistable::setOverwrite(bool newOverwrite)
    {
        overwrite = newOverwrite;
    }

    bool DefaultPersistable::getAllowNullPath() const
    {
        return allowNullPath;
    }

    void DefaultPersistable::setAllowNullPath(bool newAllowNullPath)
    {
        allowNullPath = newAllowNullPath;
    }

    std::ofstream DefaultPersistable::getFileStream() const
    {
        const std::string filename = path.string();
        auto hFile = std::ofstream(filename, std::ios_base::out);

        if (!hFile.is_open())
        {
            throw FileIOError("Could not create file: "s + filename);
        }

        return hFile;
    }

    std::ostringstream DefaultPersistable::getStringStream()
    {
        return std::ostringstream();
    }
}
