#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

#include "../typesystem/concepts.h"

#include "groupedProperties/scriptable.h"

namespace Plotypus
{
    struct TerminalInfoProvider :
        public Scriptable,
        public Persistable,
        public NamedType
    {
        static std::string getDefaultExtension();

        template<TerminalInfoProviderType T>
        T& as()
        {
            return dynamic_cast<T>(*this);
        }
    };
}

#endif // TERMINALINFOPROVIDER_H
