#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "mutable.h"
#include "persistable/persistable.h"

namespace Plotypus
{
    struct Serializable :
        public virtual Persistable,
        public virtual Mutable
    {

    };
}

#endif // SERIALIZABLE_H
