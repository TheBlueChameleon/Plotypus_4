#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

#include "base/baseproperties/mutable.h"
#include "base/baseproperties/validatable.h"

namespace Plotypus
{
    struct Scriptable :
        public Mutable,
        public Validatable
    {
        virtual void writeScript(std::ostream& hFile) const = 0;
    };
}

#endif // SCRIPTABLE_H
