#include <fstream>
#include <string>
using namespace std::string_literals;

#include "defaultpersistable.h"

namespace Plotypus
{

    ValidationResult DefaultPersistable::validate() const
    {
        ValidationResult result;

        auto fail = [&result] (const std::string& message)
        {
            result.addError<FileIOError>(message, getTypeName());
        };

        if (!allowNullPath)
        {
            if (path.empty())
            {
                fail("Filename is empty.");
            }
        }

        if (!overwrite)
        {
            if (std::filesystem::exists(path))
            {
                fail("File '"s + path.string() + "' already exists.");
            }
        }

        const auto& parentDir = path.parent_path();
        if (parentDir.empty())
        {
            // implicitly in CWD -- always valid
        }
        else
        {
            if (!makeDirectories)
            {
                if (!std::filesystem::exists(parentDir))
                {
                    fail("Directory '"s + parentDir.string() + "' does not exist.");
                }
            }
            else
            {
                if (std::filesystem::exists(parentDir) && !std::filesystem::is_directory(parentDir))
                {
                    fail("'"s + parentDir.string() + "' is not a directory.");
                }
            }
        }

        return result;
    }

    const std::string DefaultPersistable::getTypeName()
    {
        return "DefaultPersistable";
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

    std::ostringstream DefaultPersistable::getStringStream() const
    {
        return std::ostringstream();
    }
}
