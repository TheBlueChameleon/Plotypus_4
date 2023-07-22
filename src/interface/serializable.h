#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "persistable.h"

namespace Plotypus
{
    struct Serializable
    {
        virtual void reset() = 0;

    };
}

#endif // SERIALIZABLE_H
