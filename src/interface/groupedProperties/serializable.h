#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "../baseProperties/mutable.h"
#include "../baseProperties/persistable.h"

namespace Plotypus
{
    struct Serializable :
        public Persistable,
        public Mutable
    {

    };
}

#endif // SERIALIZABLE_H
