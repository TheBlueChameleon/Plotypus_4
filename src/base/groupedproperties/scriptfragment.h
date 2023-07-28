#ifndef FRAGMENT_H
#define FRAGMENT_H

#include "base/baseproperties/mutable.h"

namespace Plotypus
{
    struct ScriptFragment :
        public Mutable
    {
        virtual std::string generateScriptFragment() const = 0;
    };
}
#endif // FRAGMENT_H
