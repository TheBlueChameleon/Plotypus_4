#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

#include "persistable.h"

namespace Plotypus
{
    struct Scriptable : public Persistable
    {
        virtual bool validate() = 0;
    };
}

#endif // SCRIPTABLE_H
