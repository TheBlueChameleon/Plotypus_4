#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

#include "../baseProperties/mutable.h"
#include "../baseProperties/validatable.h"

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
