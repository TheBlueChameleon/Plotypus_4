#ifndef PROPAGATINGPERSISTABLE_H
#define PROPAGATINGPERSISTABLE_H

#include "persistable.h"

namespace Plotypus
{
    struct PropagatingPersistable : public Persistable
    {
        virtual bool getPropagateUpdateChildFileNames() const = 0;
        virtual void setPropagateUpdateChildFileNames(const bool newSetUpdateChildFileNames) = 0;

        virtual std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix = std::optional<std::string>()) = 0;

        // virtual void propagate(Collection<Persistable> children) = 0;
    };
}

#endif // PROPAGATINGPERSISTABLE_H
