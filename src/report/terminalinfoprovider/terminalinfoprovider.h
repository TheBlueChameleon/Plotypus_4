#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

#include "base/scriptable.h"

namespace Plotypus
{
    struct TerminalInfoProvider :
        public virtual Scriptable,
        public virtual Persistable
    {
        static std::string getDefaultExtension();

        template<TerminalInfoProviderType T>
        T& as()
        {
            return dynamic_cast<T&>(*this);
        }
    };
}

#endif // TERMINALINFOPROVIDER_H
