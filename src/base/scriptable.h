#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

#include "mutable.h"
#include "validatable.h"

namespace Plotypus
{
    struct Scriptable :
        public virtual Mutable,
        public virtual Validatable
    {
        virtual void writeScript(std::ostream& hFile) const = 0;
    };
}

#endif // SCRIPTABLE_H
