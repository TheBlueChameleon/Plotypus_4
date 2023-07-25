#ifndef PROPAGATINGPERSISTABLE_H
#define PROPAGATINGPERSISTABLE_H

#include "persistable.h"

namespace Plotypus
{
    struct PropagatingPersistable : public Persistable
    {
        virtual bool getPropagateUpdateChildFileNames() const = 0;
        virtual void setPropagateUpdateChildFileNames(const bool newSetUpdateChildFileNames) = 0;
    };
}

#endif // PROPAGATINGPERSISTABLE_H
