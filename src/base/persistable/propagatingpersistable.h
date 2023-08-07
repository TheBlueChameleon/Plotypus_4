#ifndef PROPAGATINGPERSISTABLE_H
#define PROPAGATINGPERSISTABLE_H

#include "persistable.h"

namespace Plotypus
{
    struct PropagatingPersistable :
        public Persistable
    {
        virtual bool getPropagateUpdateChildFileNames() const = 0;
        virtual void setPropagateUpdateChildFileNames(const bool newSetUpdateChildFileNames) = 0;

        virtual std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix = std::optional<std::string>()) = 0;

        virtual void propagate() = 0;
        virtual void addSubscriber(std::shared_ptr<Persistable>& subscriber) = 0;
        virtual void replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber) = 0;
        virtual Collection<Persistable>& getSubscribers() = 0;
        virtual const Collection<Persistable>& getSubscribers() const = 0;

    };
}

#endif // PROPAGATINGPERSISTABLE_H
