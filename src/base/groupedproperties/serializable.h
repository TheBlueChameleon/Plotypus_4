#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "base/baseproperties/mutable.h"
#include "base/baseproperties/persistable/persistable.h"

namespace Plotypus
{
    struct Serializable :
        public Persistable,
        public Mutable
    {

    };
}

#endif // SERIALIZABLE_H
