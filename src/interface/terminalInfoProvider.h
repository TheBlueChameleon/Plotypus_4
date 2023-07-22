#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

#include "../typesystem/concepts.h"

namespace Plotypus
{
    struct TerminalInfoProvider : public Scriptable
    {
        protected:
            std::filesystem::path fileCreatedByScript;

        public:
            TerminalInfoProvider(const std::filesystem::path& fileCreatedByScript) : fileCreatedByScript(fileCreatedByScript) {}

            virtual std::string getDefaultExtension() = 0;

            template<TerminalInfoProviderType T>
            T& as()
            {
                return dynamic_cast<T>(*this);
            }
    };
}

#endif // TERMINALINFOPROVIDER_H
