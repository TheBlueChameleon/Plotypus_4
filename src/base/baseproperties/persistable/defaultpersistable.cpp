#include <fstream>
#include <string>
using namespace std::string_literals;

#include "defaultpersistable.h"

namespace Plotypus
{
    ValidationResult DefaultPersistable::validate() const
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

    std::string DefaultPersistable::getInstanceName() const
    {
        return getTypeName();
    }

    std::string DefaultPersistable::getTypeName()
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

    bool DefaultPersistable::operator ==(const Persistable &other) const
    {
        bool result = true;

        result &= (path == other.getPath());
        result &= (makeDirectories == other.getMakeDirectories());
        result &= (overwrite == other.getOverwrite());
        result &= (allowNullPath == other.getAllowNullPath());

        return result;
    }

    // ====================================================================== //

    DefaultPersistable_SP::DefaultPersistable_SP():
        m(std::make_shared<DefaultPersistable>())
    {}

    std::shared_ptr<DefaultPersistable>& DefaultPersistable_SP::get()
    {
        return m;
    }

    std::string DefaultPersistable_SP::getInstanceName() const
    {
        return m->getInstanceName();
    }

    std::string DefaultPersistable_SP::getTypeName()
    {
        return DefaultPersistable::getTypeName();
    }

    void DefaultPersistable_SP::reset()
    {
        m->reset();
    }

    const std::filesystem::path& DefaultPersistable_SP::getPath() const
    {
        return m->getPath();
    }

    void DefaultPersistable_SP::setPath(const std::filesystem::path& newPath)
    {
        m->setPath(newPath);
    }

    bool DefaultPersistable_SP::getMakeDirectories() const
    {
        return m->getMakeDirectories();
    }

    void DefaultPersistable_SP::setMakeDirectories(bool newMakeDirectories)
    {
        m->setMakeDirectories(newMakeDirectories);
    }

    bool DefaultPersistable_SP::getOverwrite() const
    {
        return m->getOverwrite();
    }

    void DefaultPersistable_SP::setOverwrite(bool newOverwrite)
    {
        m->setOverwrite(newOverwrite);
    }

    bool DefaultPersistable_SP::getAllowNullPath() const
    {
        return m->getAllowNullPath();
    }

    void DefaultPersistable_SP::setAllowNullPath(bool newAllowNullPath)
    {
        m->setAllowNullPath(newAllowNullPath);
    }

    std::ofstream DefaultPersistable_SP::getFileStream() const
    {
        return m->getFileStream();
    }

    std::ostringstream DefaultPersistable_SP::getStringStream() const
    {
        return m->getStringStream();
    }

    bool DefaultPersistable_SP::operator ==(const Persistable& other) const
    {
        return *m == other;
    }

    ValidationResult DefaultPersistable_SP::validate() const
    {
        return m->validate();
    }
}
