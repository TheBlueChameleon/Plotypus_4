#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "mutable.h"
#include "persistable/persistable.h"

namespace Plotypus
{
    struct Serializable :
        public Persistable,
        public Mutable
    {

    };
}

#endif // SERIALIZABLE_H
