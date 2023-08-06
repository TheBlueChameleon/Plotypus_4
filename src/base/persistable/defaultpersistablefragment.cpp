#include <fstream>
#include <string>
using namespace std::string_literals;

#include "defaultpersistablefragment.h"

namespace Plotypus
{
    std::string DefaultPersistableFragment::getInstanceName() const
    {
        return getTypeName();
    }

    std::string DefaultPersistableFragment::getTypeName()
    {
        return "DefaultPersistableFragment";
    }

    void DefaultPersistableFragment::reset()
    {
        path.clear();
        makeDirectories = true;
        overwrite = false;
        allowNullPath = false;
    }

    const std::filesystem::path& DefaultPersistableFragment::getPath() const
    {
        return path;
    }

    void DefaultPersistableFragment::setPath(const std::filesystem::path& newPath)
    {
        path = newPath;
    }

    bool DefaultPersistableFragment::getMakeDirectories() const
    {
        return makeDirectories;
    }

    void DefaultPersistableFragment::setMakeDirectories(bool newMakeDirectories)
    {
        makeDirectories = newMakeDirectories;
    }

    bool DefaultPersistableFragment::getOverwrite() const
    {
        return overwrite;
    }

    void DefaultPersistableFragment::setOverwrite(bool newOverwrite)
    {
        overwrite = newOverwrite;
    }

    bool DefaultPersistableFragment::getAllowNullPath() const
    {
        return allowNullPath;
    }

    void DefaultPersistableFragment::setAllowNullPath(bool newAllowNullPath)
    {
        allowNullPath = newAllowNullPath;
    }

    std::ofstream DefaultPersistableFragment::getFileStream() const
    {
        const std::string filename = path.string();
        auto hFile = std::ofstream(filename, std::ios_base::out);

        if (!hFile.is_open())
        {
            throw FileIOError("Could not create file: "s + filename);
        }

        return hFile;
    }

    std::ostringstream DefaultPersistableFragment::getStringStream() const
    {
        return std::ostringstream();
    }

    bool DefaultPersistableFragment::operator==(const Persistable& other) const
    {
        bool result = true;

        result &= (path == other.getPath());
        result &= (makeDirectories == other.getMakeDirectories());
        result &= (overwrite == other.getOverwrite());
        result &= (allowNullPath == other.getAllowNullPath());

        return result;
    }

    ValidationResult DefaultPersistableFragment::validate() const
    {
        ValidationResult result;

        auto fail = [&result, this](const std::string& message)
        {
            result.addError<FileIOError>(message, getTypeName());
        };

        if (!allowNullPath)
        {
            if (path.empty())
            {
                result.addError<InvalidFilenameError>("Filename is empty.", getTypeName());
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
}
