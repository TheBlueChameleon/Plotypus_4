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

    std::filesystem::path DefaultPropagatingPersistable::getDerivedPath(const std::string& extension, std::optional<std::string> infix)
    {
        const std::filesystem::path parentDir = getPath().parent_path();
        const std::filesystem::path stem = getPath().stem();
        std::filesystem::path result = parentDir / stem;

        if (infix.has_value())
        {
            result += infix.value();
        }

        result.replace_extension(extension);
        return result;
    }


    void DefaultPropagatingPersistable::updateChildFileNames()
    {
        for (int idx = 1; std::shared_ptr<Persistable>& subscriber : subscribers.expose())
        {
            // rename
            const std::string ext = subscriber->getPath().extension();
            const auto childFilePath = getDerivedPath(ext, "_" + std::to_string(idx));
            subscriber->setPath(childFilePath);
            ++idx;

            // propagate
            if (propagateUpdateChildFileNames)
            {
                {
                    PropagatingPersistable* propagatingSubscriber = std::dynamic_pointer_cast<PropagatingPersistable>(subscriber).get();
                    if (propagatingSubscriber)
                    {
                        propagatingSubscriber->updateChildFileNames();
                    }
                }
            }
        }

    }

    void DefaultPropagatingPersistable::addSubscriber(std::shared_ptr<Persistable>& subscriber)
    {
        subscribers.add(subscriber);
    }

    void DefaultPropagatingPersistable::replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber)
    {
        findAndReplace(subscribers.expose(), oldSubscriber, newSubscriber);
    }

    Collection<Persistable>& DefaultPropagatingPersistable::getSubscribers()
    {
        return subscribers;
    }

    const Collection<Persistable>& DefaultPropagatingPersistable::getSubscribers() const
    {
        return subscribers;
    }

    std::string DefaultPropagatingPersistable::getInstanceName() const
    {
        return getTypeName();
    }

    std::string DefaultPropagatingPersistable::getTypeName()
    {
        return "DefaultPropagatingPersistable";
    }

    void DefaultPropagatingPersistable::reset()
    {
        DefaultPersistableFragment::reset();
        subscribers.clear();
        propagateUpdateChildFileNames = true;
    }

    ValidationResult DefaultPropagatingPersistable::validate() const
    {
        ValidationResult result;
        const std::string stackTraceElement = getInstanceName();
        result.absorbValidationResult(DefaultPersistableFragment::validate(), stackTraceElement);

        bool hasNullPointers = false;
        subscribers.forEachExposed([&hasNullPointers](const Persistable* ptr)
        {
            hasNullPointers |= (ptr == nullptr);
        });
        if (hasNullPointers)
        {
            result.addError<IncompleteDescritporError>("At least one subscriber is a null pointer", stackTraceElement);
        }

        return result;
    }

    const std::filesystem::path& DefaultPropagatingPersistable::getPath() const
    {
        return DefaultPersistableFragment::getPath();
    }

    void DefaultPropagatingPersistable::setPath(const std::filesystem::path& newPath)
    {
        DefaultPersistableFragment::setPath(newPath);
    }

    bool DefaultPropagatingPersistable::getMakeDirectories() const
    {
        return DefaultPersistableFragment::getMakeDirectories();
    }

    void DefaultPropagatingPersistable::setMakeDirectories(bool newMakeDirectories)
    {
        DefaultPersistableFragment::setMakeDirectories(newMakeDirectories);
    }

    bool DefaultPropagatingPersistable::getOverwrite() const
    {
        return DefaultPersistableFragment::getOverwrite();
    }

    void DefaultPropagatingPersistable::setOverwrite(bool newOverwrite)
    {
        DefaultPersistableFragment::setOverwrite(newOverwrite);
    }

    bool DefaultPropagatingPersistable::getAllowNullPath() const
    {
        return DefaultPersistableFragment::getAllowNullPath();
    }

    void DefaultPropagatingPersistable::setAllowNullPath(bool newAllowNullPath)
    {
        DefaultPersistableFragment::setAllowNullPath(newAllowNullPath);
    }

    std::ofstream DefaultPropagatingPersistable::getFileStream() const
    {
        return DefaultPersistableFragment::getFileStream();
    }

    std::ostringstream DefaultPropagatingPersistable::getStringStream() const
    {
        return DefaultPersistableFragment::getStringStream();
    }

    bool DefaultPropagatingPersistable::operator ==(const Persistable& other) const
    {
        bool result = true;

        const PropagatingPersistable* otherPropagating = dynamic_cast<const PropagatingPersistable*>(&other);
        if (otherPropagating)
        {
            const DefaultPersistableFragment* thisBase = static_cast<const DefaultPersistableFragment*>(this);
            result &= (*thisBase == other);

            result &= (propagateUpdateChildFileNames == otherPropagating->getPropagateUpdateChildFileNames());
            result &= (subscribers == otherPropagating->getSubscribers());
        }
        else
        {
            return false;
        }

        return result;

    }
}
