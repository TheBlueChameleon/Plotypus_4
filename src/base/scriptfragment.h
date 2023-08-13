#ifndef FRAGMENT_H
#define FRAGMENT_H

#include "mutable.h"

namespace Plotypus
{
    struct ScriptFragment :
        public virtual Mutable
    {
        virtual void writeScriptFragment(std::ostream& hFile) const = 0;
        virtual std::string generateScriptFragment() const;
    };
}
#endif // FRAGMENT_H
